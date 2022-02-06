#pragma region std_includes
#include <iostream>
#include <vector>
#include <string>
#include <windows.h>
#include <regex>
#include <conio.h>
#include <thread>
#include <fstream>
#include <map>
#include <algorithm>
#include <stack>
#pragma endregion

#pragma region ttm_declaration
#ifndef THETIMEMACHINE
#define THETIMEMACHINE

namespace ttm
{
  class theTimeMachine
  {
  public:
    const std::vector<std::string> privilegeVec = { "add" };
    const std::vector<std::string> commandsVec = { "enable", "disable", "search" };

  public:
    bool privilege = false;
    bool type;
    const std::string info = "Press ENTER to get started!\n\n";
    std::string prefix = "cli>";
    std::string str = "";
    std::string year;
    std::string name;
    std::string outcome;
    int counter = 0;
    char ch;
    std::vector<std::string> words;
    std::stack<std::string> stack;

  public:
    void getLine()
    {
      std::cout << prefix;
      type = true;
      while (type)
      {
        ch = _getche();
        str += ch;
        if (ch == '?')
        {
          type = false;
          std::cout << '\n';
          str.pop_back();
          getHelp();
          counter = 0;
          getLine();
        }
        if (ch == '\b')
        {
          if (counter > 0)
          {
            std::cout << ' ' << '\b';
            str.pop_back();
            str.pop_back();
            counter--;
          }
          else
          {
            std::cout << ((privilege) ? '#' : '>');
            str.pop_back();
          }
        }
        else
        {
          counter++;
        }
        if (ch == '\r')
        {
          type = false;
          std::cout << '\n';
          str.pop_back();
          stack.push(str);
          getCommand();
          counter = 0;
          getLine();
        }
        if (ch == 72)
        {
          counter -= 2;
          std::cout << '\b' << ' ' << '\b';
          str.pop_back();
          str.pop_back();
          getLastCommand();
        }
        if (ch == 71 || ch == 73 || ch == 75 || ch == 76 || ch == 77 || ch == 79 || ch == 80 || ch == 81 || ch == 82 || ch == 83)
        {
          counter -= 2;
          std::cout << '\b' << ' ' << '\b';
          str.pop_back();
          str.pop_back();
        }
      }
    }
    void getCommand()
    {
      int c = 1;
      std::string temp = "";
      for (int i = 0; i < str.length(); ++i)
      {
        if (str[i] == ' ')
        {
          words.push_back(temp);
          temp = "";
        }
        else
        {
          temp.push_back(str[i]);
        }
      }
      words.push_back(temp);
      for (size_t i = 0; i < commandsVec.size(); ++i)
      {
        if (words[0] == commandsVec[i])
        {
          break;
        }
        else
        {
          if (i == commandsVec.size() - 1)
          {
            std::cout << ((str == "")?"":"% Unknown command.\n");
          }
          c++;
        }
      }
      switch (c)
      {
      case 1:
        prefix = "cli#";
        privilege = true;
        break;

      case 2:
        prefix = "cli>";
        privilege = false;
        break;

      case 3:
        if(words.size() > 1)
        {
          if (words[1] == "year")
          {
            if(words.size() > 2)
            {
              year = words[2];
            }
            else
            {
              std::cout << "% Incomplete command.\n";
            }
          }
          else if(words[1] == "name")
          {
            if(words.size() > 2)
            {
              name = words[2];
            }
            else
            {
              std::cout << "% Incomplete command.\n";
            }
          }
          else if(words[1] == "outcome")
          {
            if(words.size() > 2)
            {
              outcome = words[2];
            }
            else
            {
              std::cout << "% Incomplete command.\n";
            }
          }
          else
          {
            std::cout << "% Invalid input detected at the second index.\n";
          }
        }
        else
        {
          std::cout << "% Incomplete command.\n";
        }
        break;

      default:
        break;
      }
      words.clear();
      theTimeMachine::str.clear();
      c = 1;
    }
    void getLastCommand()
    {
      if (stack.empty())
      {
        std::cout << "\n% There are no signs of last commands used.\n";
        str.clear();
        getLine();
      }
      else
      {
        while (counter != 0)
        {
          std::cout << '\b' << ' ' << '\b';
          counter--;
        }
        counter += stack.top().size();
        str = stack.top();
        std::cout << stack.top();
      }
    }
    void getHelp()
    {
      stack.push(str);
      int c = 0;
      std::string temp = "";
      for (int i = 0; i < str.length(); ++i)
      {
        if (str[i] == ' ')
        {
          words.push_back(temp);
          temp = "";
        }
        else
        {
          temp.push_back(str[i]);
        }
      }
      words.push_back(temp);
      if(words[0] == "")
      {
        for (int i = 0; i < commandsVec.size(); ++i)
        {
          std::cout << "  " << commandsVec[i] << '\n';
        }
        if(privilege)
        {
            for (int i = 0; i < privilegeVec.size(); ++i)
            {
              std::cout << "  " << privilegeVec[i] << '\n';
            }
        }
      }
      else
      {
        for (int i = 0; i < commandsVec.size(); ++i)
        {
          if (words[0] == commandsVec[i])
          {
            c++;
            break;
          }
          else
          {
            if (i == commandsVec.size() - 1)
            {
              std::cout << "% Unknown command.\n";
            }
            c++;
          }
        }
      }
      switch (c)
      {
      case 1:
        std::cout << "  <cr>\n";
        break;

      case 2:
        std::cout << "  <cr>\n";
        break;

      case 3:
        if(words.size() > 1)
        {
          if (words[1] == "year")
          {
            if(words.size() > 2)
            {
              std::cout << "  NUMBER  Year of the battle\n";
            }
            else
            {
              std::cout << "  year\n  name\n  outcome\n";
            }
          }
          else if(words[1] == "name")
          {
            if(words.size() > 2)
            {
              std::cout << "  WORD  Name of the battle\n";
            }
            else
            {
              std::cout << "  year\n  name\n  outcome\n";
            }
          }
          else if(words[1] == "outcome")
          {
            if(words.size() > 2)
            {
              std::cout << "  Win/Loss  Outcome of the battle\n";
            }
            else
            {
              std::cout << "  year\n  name\n  outcome\n";
            }
          }
          else
          {
            std::cout << "  year\n  name\n  outcome\n";
          }
        }
        else
        {
          std::cout << "  search\n";
        }
        break;

      default:
        break;
      }
      words.clear();
      theTimeMachine::str.clear();
      c = 1;
    }
  };
}
#endif // THETIMEMACHINE
#pragma endregion

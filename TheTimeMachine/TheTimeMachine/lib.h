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

#pragma region ttd_declaration
#ifndef THETIMEMACHINE
#define THETIMEMACHINE
namespace ttd
{
  class theTimeMachine
  {
  public:
    std::string commands = "enable disable search";
    std::vector<std::string> commandsVec;

  public:
    bool privilege = false;
    bool type;
    std::string info = "";
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
          std::cout << "\ninsert help menu here :D\n";
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
      std::string vecTemp = "";
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
      for (int i = 0; i < commands.length(); ++i)
      {
        if (commands[i] == ' ')
        {
          commandsVec.push_back(vecTemp);
          vecTemp = "";
        }
        else
        {
          vecTemp.push_back(commands[i]);
        }
      }
      commandsVec.push_back(vecTemp);
      words.push_back(temp);
      for (int i = 0; i < commandsVec.size(); ++i)
      {
        if (words[0] == commandsVec[i])
        {
          break;
        }
        else
        {
          if (i == commandsVec.size() - 1)
          {
            std::cout << "% Incorrect command.\n";
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

      default:
        break;
      }
      words.clear();
      commandsVec.clear();
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
  };
}
#endif // THETIMEMACHINE
#pragma endregion

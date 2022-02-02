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
#pragma endregion

#pragma region ttd_declaration
#ifndef THETIMEMACHINE
#define THETIMEMACHINE
namespace ttd
{
  class theTimeMachine
  {
  public:
    std::string commands = "enable disable";
    std::vector<std::string> commandsVec;

  public:
    bool privilege = false;
    bool type;
    std::string info = "";
    std::string prefix = "cli>";
    std::string str = "";
    int counter = 0;
    char ch;
    std::vector<std::string> words;

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
        if (ch == '\r')
        {
          type = false;
          std::cout << '\n';
          str.pop_back();
          getCommand();
          counter = 0;
          getLine();
        }
        if (ch == '\b')
        {
          if (counter > 0)
          {
            std::cout << ' ' << '\b';
            str.pop_back();
            counter--;
          }
          else
          {
            std::cout << ((privilege)?'#':'>');
            str.pop_back();
          }
        }
        else
        {
          counter++;
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
          if(i == commandsVec.size() - 1)
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

      default:
        break;
      }
      words.clear();
      commandsVec.clear();
      theTimeMachine::str.clear();
      c = 1;
    }
  };
}
#endif // THETIMEMACHINE
#pragma endregion

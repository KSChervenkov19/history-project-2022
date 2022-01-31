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
		bool privilege;
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
					if(counter > 0)
					{
						std::cout << ' ' << '\b';
						str.pop_back();
						counter--;
					}
					else
					{
						std::cout << '>';
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
				std::cout << words[0] << std::endl;
				std::cout << commandsVec[i] << std::endl;
				if (words[0] == commandsVec[i])
				{
					std::cout << "gay" << std::endl;
				}
				else
				{
					std::cout << "nono" << std::endl;
				}
			}
			words.clear();
			commandsVec.clear();
			theTimeMachine::str.clear();
		}
	};
}
#endif // THETIMEMACHINE
#pragma endregion

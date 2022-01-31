#pragma region std_includes
#include <iostream>
#include <vector>
#include <string>
#include <windows.h>
#include <regex>
#include <conio.h>
#include <thread>
#include <fstream>
#include <algorithm>
#pragma endregion

#pragma region ttd_declaration
#ifndef THETIMEMACHINE
#define THETIMEMACHINE
namespace ttd
{
	class theTimeMachine;
	enum commands
	{
		enable
	};
	class theTimeMachine
	{
	public:
		bool privilege;
		bool type;
		std::string info = "";
		std::string prefix = "cli>";
		std::string str = " ";
		int counter = 0;
		char ch;
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
			std::cout << '\n' << theTimeMachine::str << '\n';
			theTimeMachine::str.clear();
		}
	};
}
#endif // THETIMEMACHINE
#pragma endregion

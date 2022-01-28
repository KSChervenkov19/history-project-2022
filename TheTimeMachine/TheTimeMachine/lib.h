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
		void getCommand()
		{
			std::cout << prefix;
			type = true;
			while (type)
			{
				ch = _getch();
				str += ch;
				std::cout << ch;
				if (ch == '?')
				{
					type = false;
					std::cout << "\ninsert help menu here :D\n";
					getCommand();
				}
				if (ch == '\b')
				{
					if(counter > 0)
					{
						std::cout << ' ';
						std::cout << '\b';
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
	};
}
#pragma endregion

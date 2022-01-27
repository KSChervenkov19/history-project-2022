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
		commands
	};
	class theTimeMachine
	{
	public:
		bool privilege;
		std::string info = "";
		std::string prefix = "cli>";
		std::string str = " ";
	public:
		void getCommand()
		{
			std::cout << prefix;
			while (true)
			{
				str += getchar();
				if (str.back() == '\n')
				{
					break;
				}
			}
		}
	};
}
#pragma endregion

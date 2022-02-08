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
		bool typing = false;
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
		std::map<std::string, void(*)(std::string)> commandsMap;

	public:
		void getLine()
		{
			std::cout << prefix;
			typing = true;
			while (typing)
			{
				ch = _getche();
				str += ch;
				if (ch == '?')
				{
					typing = false;
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
					typing = false;
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
			int i = 0;
			bool globalBreak = false;
			for (std::string currentWord : commandsVec)
			{
				if (globalBreak) break;
				i++;
				if (words[0] == currentWord)
				{
					executeCommand(currentWord);
					break;
				}
				else
				{
					if (privilege)
					{
						for (std::string currentPrivilegeWord : privilegeVec)
						{
							if (words[0] == currentPrivilegeWord)
							{
								executeHelp(currentPrivilegeWord);
								globalBreak = true;
								break;
							}
						}
					}
					if (i == commandsVec.size())
					{
						std::cout << ((str == "") ? "" : "% Unknown command.\n");
					}
				}
			}
			words.clear();
			theTimeMachine::str.clear();
		}

		void executeCommand(std::string currentWord)
		{
			if (currentWord == "enable")
			{
				enable();
			}
			else if (currentWord == "disable")
			{
				disable();
			}
			else if (currentWord == "search")
			{
				search();
			}
			else if (currentWord == "add")
			{
				add();
			}
		}

		void enable()
		{
			prefix = "cli#";
			privilege = true;
		}

		void disable()
		{
			prefix = "cli>";
			privilege = false;
		}

		void search()
		{
			if (words.size() > 1)
			{
				if (words[1] == "year")
				{
					if (words.size() > 2)
					{
						std::cout << year;
						year = words[2];
						findEventByYear();
					}
					else
					{
						std::cout << "% Incomplete command.\n";
					}
				}
				else if (words[1] == "name")
				{
					if (words.size() > 2)
					{
						name = words[2];
					}
					else
					{
						std::cout << "% Incomplete command.\n";
					}
				}
				else if (words[1] == "outcome")
				{
					if (words.size() > 2)
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
		}

		void add()
		{
			std::cout << "yeye";
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

			int i = 0;
			if (words[0] == "")
			{
				for (std::string currentCommand : commandsVec)
				{
					std::cout << "  " << currentCommand << '\n';
				}
				if (privilege)
				{
					for (std::string currentPrivilegeCommand : privilegeVec)
					{
						std::cout << "  " << currentPrivilegeCommand << '\n';
					}
				}
			}
			else
			{
				bool globalBreak = false;
				for (std::string currentWord : commandsVec)
				{
					if (globalBreak) break;
					i++;
					if (words[0] == currentWord)
					{
						executeHelp(currentWord);
						break;
					}
					else
					{
						if (privilege)
						{
							for (std::string currentPrivilegeCommand : privilegeVec)
							{
								if (words[0] == currentPrivilegeCommand)
								{
									executeHelp(currentPrivilegeCommand);
									globalBreak = true;
									break;
								}
							}
						}
						if (i == privilegeVec.size() - 1)
						{
							std::cout << ((str == "") ? "" : "% Unknown command.\n");
						}
					}
				}
			}

			words.clear();
			theTimeMachine::str.clear();
		}

		void executeHelp(std::string currentWord)
		{
			if (currentWord == "enable")
			{
				enableHelp();
			}
			else if (currentWord == "disable")
			{
				disableHelp();
			}
			else if (currentWord == "search")
			{
				searchHelp();
			}
			else if (currentWord == "add")
			{
				addHelp();
			}
		}

		void enableHelp()
		{
			std::cout << "  <cr>\n";
		}

		void disableHelp()
		{
			std::cout << "  <cr>\n";
		}

		void searchHelp()
		{
			if (words.size() > 1)
			{
				if (words[1] == "year")
				{
					if (words.size() > 2)
					{
						std::cout << "  NUMBER  Year of the battle\n";
					}
					else
					{
						std::cout << "  year\n  name\n  outcome\n";
					}
				}
				else if (words[1] == "name")
				{
					if (words.size() > 2)
					{
						std::cout << "  WORD  Name of the battle\n";
					}
					else
					{
						std::cout << "  year\n  name\n  outcome\n";
					}
				}
				else if (words[1] == "outcome")
				{
					if (words.size() > 2)
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
		}

		void addHelp()
		{
			std::cout << "yeye\n";
		}

		void findEventByYear()
		{
			std::cout << year;
			int year2 = std::stoi(year);
			std::cout << "i a,m workin" << year2;
			year.clear();
		}
	};
}
#endif // THETIMEMACHINE
#pragma endregion

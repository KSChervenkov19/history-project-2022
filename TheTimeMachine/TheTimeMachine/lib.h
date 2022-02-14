#include "data.h"

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
		bool startWriting = false;
		int intYear;
		char ch;
		const std::string info = "Bulgaria's Battles Time Machine, TTM Software, Version 12.2 (25), RELEASE SOFTWARE (fc1)\nCompiled by ttm_team\n\nPress ENTER to get started!\n\n";
		std::string prefix = "cli>";
		std::string str = "";
		std::string year;
		std::string name;
		std::string outcome;
		size_t counter = 0;
		std::vector<std::string> words;
		std::stack<std::string> stack;
		std::vector<std::string> eventParameters;

	public:
		void getLine(data* linkedListData)
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
					getHelp(linkedListData);
					counter = 0;
					getLine(linkedListData);
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
					getCommand(linkedListData);
					counter = 0;
					getLine(linkedListData);
				}
				if (ch == 72)
				{
					counter -= 2;
					std::cout << '\b' << ' ' << '\b';
					str.pop_back();
					str.pop_back();
					getLastCommand(linkedListData);
				}
			}
		}
		void getCommand(data* linkedListData)
		{
			std::string temp = "";
			std::string addCommandTemp = "";
			for (size_t i = 0; i < str.length(); ++i)
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
			for (size_t i = 0; i < str.length(); ++i)
			{
				if (str[i] == '\"')
				{
					startWriting = !startWriting;
					i++;
				}
				if (startWriting)
				{
					addCommandTemp.push_back(str[i]);
				}
				else
				{
					eventParameters.push_back(addCommandTemp);
					if (eventParameters.back() == "")
					{
						eventParameters.pop_back();
					}
					addCommandTemp = "";
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
					executeCommand(currentWord, linkedListData);
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
								executeCommand(currentPrivilegeWord, linkedListData);
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
			eventParameters.clear();
			theTimeMachine::str.clear();
		}

		void executeCommand(std::string currentWord, data* linkedListData)
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
				search(linkedListData);
			}
			else if (currentWord == "add")
			{
				add(linkedListData);
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

		void search(data* linkedListData)
		{
			if (words.size() > 1)
			{
				if (words[1] == "year")
				{
					if (words.size() > 2)
					{
						year = words[2];
						intYear = std::stoi(year);
						linkedListData->findEventByYear(intYear);
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
						for (size_t i = 2; i < words.size(); i++)
						{
							name += words[i] + " ";
						}
						name.pop_back();
						linkedListData->findEventByName(name);
						name.clear();
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
						linkedListData->findEventByOutcome(outcome);
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

		void add(data* linkedListData)
		{

			if (eventParameters.size() == 5)
			{
				linkedListData->addData(eventParameters);
			}
			else
			{
				std::cout << "% Incorrect parameters.\n";
			}
		}

		void getLastCommand(data* linkedListData)
		{
			if (stack.empty())
			{
				std::cout << "\n% There are no signs of last commands used.\n";
				getLine(linkedListData);
			}
			else
			{
				while (counter != 0)
				{
					std::cout << '\b' << ' ' << '\b';
					counter--;
				}
				counter += stack.top().size();
				str.clear();
				str = stack.top();
				std::cout << stack.top();
			}
		}

		void getHelp(data* linkedListData)
		{
			stack.push(str);
			std::string temp = "";
			for (size_t i = 0; i < str.length(); ++i)
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
						executeHelp(currentWord, linkedListData);
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
									executeHelp(currentPrivilegeCommand, linkedListData);
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

		void executeHelp(std::string currentWord, data* linkedListData)
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
				searchHelp(linkedListData);
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

		void searchHelp(data* linkedListData)
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
						std::cout << "  WORD  Name of the battle\n\n";
						std::cout << "  All available names: \n";
						linkedListData->displayNames();
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
				if (words.size() > 1)
				{
					std::cout << "  WORD \"name\"  NUMBER \"year\"  Win/Loss \"outcome\"  WORD \"description\"  WORD \"reason\"\n  NOTE: Space each parameter with quotation marks\n";
				}
				else
				{
					std::cout << "  add\n";
				}
		}
	};
}
#endif // THETIMEMACHINE
#pragma endregion

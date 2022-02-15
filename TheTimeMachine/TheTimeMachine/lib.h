#include "data.h"

#pragma region help
/*
	lib.h

	What is this?
	~~~~~~~~~~~~~
	ttm::theTimeMachine is a single file, cisco/switch style based command line interface
	It is developed by ttm_team as an assistive tool for their project.

	This file provides the core utility set of the ttm::theTimeMachine, including
	cisco/switch style typing, help menus, use of other external functions, privilege mode and a bunch of utility
	types.

	How to use the cli?
	~~~~~~~~~~~~~
	If you haven't ever configured a switch or worked with cisco's cli, you
	can learn the syntax of the application by reading "docs/userGuide.docx"

	Author
	~~~~~~
	ttm_team
*/
#pragma endregion

#pragma region ttm_declaration
#ifndef THETIMEMACHINE
#define THETIMEMACHINE
namespace ttm
{
	class theTimeMachine
	{
	public:
		//command vectors
		const std::vector<std::string> privilegeVec = { "add", "delete" };
		const std::vector<std::string> commandsVec = { "enable", "disable", "search", "clear"};

	public:
		//public variables
		int intYear;
		const std::string info = "Bulgaria's Battles Time Machine, TTM Software, Version 12.2 (25), RELEASE SOFTWARE (fc1)\nCompiled by ttm_team\n\nPress ENTER to get started!\n\n";
		std::string str = "";
		std::string year;
		std::string name;
		std::string outcome;
		std::vector<std::string> eventParameters;

	private:
		//private variables
		bool privilege = false;
		bool typing = false;
		bool startWriting = false;
		char ch;
		size_t counter = 0;
		std::string prefix = "cli>";
		std::string regexStr = "";
		std::vector<std::string> words;
		std::stack<std::string> stack;

	public:
		//main lib.h function for getting line
		void getLine(data* linkedListData)
		{
			std::cout << prefix;
			typing = true;
			if(regexStr != "") std::cout << regexStr;
			regexStr = "";
			while (typing)
			{
				ch = _getche();
				str += ch;

				//checking for menu call
				if (ch == '?')
				{
					typing = false;
					std::cout << '\n';
					str.pop_back();
					getHelp(linkedListData);
					counter = 0;
					getLine(linkedListData);
				}

				//checking for backspace/deletion
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

				//checking for new line/executing command
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

				//checking for up arrow click
				if (ch == 72)
				{
					counter -= 2;
					std::cout << '\b' << ' ' << '\b';
					str.pop_back();
					str.pop_back();
					getLastCommand(linkedListData);
				}

				if (ch == '\t')
				{
					autoComplete(linkedListData);
				}
			}
		}

		//typed command checking
		void getCommand(data* linkedListData)
		{
			std::string temp = "";
			std::string addCommandTemp = "";
			//devide the string into words via whitespaces
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
			//devide string into words via quotation marks for the add command
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
			//check if the command typed is contained in the commands vector
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
		
		//redirect into function depending on the word typed
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
			else if (currentWord == "delete")
			{
				deleteEvent(linkedListData);
			}
			else if (currentWord == "clear")
			{
				clear();
			}
		}

		//enables privilege mode
		void enable()
		{
			prefix = "cli#";
			privilege = true;
		}

		//disables privilege mode
		void disable()
		{
			prefix = "cli>";
			privilege = false;
		}

		//search for an event and call the corresponding function
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
				else if (words[1] == "all")
				{
					linkedListData->displayAll();
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

		//add new event
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

		//delete events
		void deleteEvent(data* linkedListData)
		{
			linkedListData->deleteCustomList();
		}

		//clear the console
		void clear()
		{
			system("cls");
		}

		//get the last command entered and display it
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

		//display help menu corresponding to the command
		void getHelp(data* linkedListData)
		{
			stack.push(str);
			std::string temp = "";
			//devide the string into words via whitespaces
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
			//check if the command typed is contained in the commands vector
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
						if (i == commandsVec.size())
						{
							std::cout << ((str == "") ? "" : "% Unknown command.\n");
						}
					}
				}
			}

			words.clear();
			theTimeMachine::str.clear();
		}

		//redirect into function depending on the word typed
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
			else if (currentWord == "delete")
			{
				deleteHelp();
			}
			else if (currentWord == "clear")
			{
				clearHelp();
			}
		}

		//display help menu for the enable command
		void enableHelp()
		{
			std::cout << "  <cr>\n";
		}

		//display help menu for the disable command
		void disableHelp()
		{
			std::cout << "  <cr>\n";
		}

		//display help menu for the search command depending on the second word
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
						std::cout << "  year\n  name\n  outcome\n  all\n";
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
						std::cout << "  year\n  name\n  outcome\n  all\n";
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
						std::cout << "  year\n  name\n  outcome\n  all\n";
					}
				}
				else if (words[1] == "all")
				{
					std::cout << "  <cr>\n";
				}
				else
				{
					std::cout << "  year\n  name\n  outcome\n  all\n";
				}
			}
			else
			{
				std::cout << "  search\n";
			}
		}

		//display help menu for the add command
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

		//display help menu for the delete command
		void deleteHelp()
		{
			std::cout << "  <cr>\n";
		}

		//display help menu for the clear command
		void clearHelp()
		{
			std::cout << "  <cr>\n";
		}

		void autoComplete(data* linkedListData)
		{
			str.pop_back();
			std::cout << '\n';
			counter = 0;
			std::regex strExpr("(" + str + ")(.*)");
			if (!privilege)
			{
				for (std::string currentCommand : commandsVec)
				{
					std::string command(currentCommand);
					if (std::regex_match(command, strExpr))
					{
						regexStr = currentCommand;
						str = regexStr;
						stack.push(regexStr);
						counter = currentCommand.size();
						getLine(linkedListData);
					}
				}
			}
			else
			{
				for (std::string currentCommand : commandsVec)
				{
					std::string command(currentCommand);
					if (std::regex_match(command, strExpr))
					{
						regexStr = currentCommand;
						str = regexStr;
						stack.push(regexStr);
						counter = currentCommand.size();
						getLine(linkedListData);
					}
				}
				for (std::string currentCommand : privilegeVec)
				{
					std::string command(currentCommand);
					if (std::regex_match(command, strExpr))
					{
						regexStr = currentCommand;
						str = regexStr;
						stack.push(regexStr);
						counter = currentCommand.size();
						getLine(linkedListData);
					}
				}
			}
		}
	};
}
#endif // THETIMEMACHINE
#pragma endregion

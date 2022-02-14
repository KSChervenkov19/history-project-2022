#pragma once

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

class data
{
	public:
		struct NODE {
			int id;
			std::string name;
			int year;
			std::string outcome;
			std::string description;
			std::string reason;
			std::string area;
			int grayCode;
			NODE* next;
		};
		std::vector <NODE*> events;
		int closestYear;
		int thatYear;
		bool found;
		std::fstream manageData;
		NODE* head;
		NODE* tail;
		NODE* old;

	public:
		void createNodes();
		void deleteNodes();
		void displayNames();
		void findEventByYear(int year);
		void findEventByName(std::string name);
		void findEventByOutcome(std::string outcome);
		void addData(std::vector <std::string> eventParams);
		void getData();
		void addNode(std::string name, int year, std::string outcome, std::string description, std::string reason);
		int convertToGray(int num);
};
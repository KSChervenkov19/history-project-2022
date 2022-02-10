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

	public:
		void createBaseNodes();
		void displayNames();
		void findEventByYear(int year);
		void findEventByName(std::string name);
		void findEventByOutcome(std::string outcome);
};
#pragma once
#include "lib.h"

class data
{
	public:
		struct NODE {
			int id;
			std::string name;
			int year;
			bool outcome;
			std::string description;
			std::string goal;
			std::string area;
			int grayCode;
			NODE* next;
		};

	private:
};
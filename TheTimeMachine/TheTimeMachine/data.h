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
			std::string reason;
			std::string area;
			int grayCode;
			NODE* next;
		};

		/*
		private:
			NODE *head, *tail;
		*/

	public:
		void createBaseNodes();
};
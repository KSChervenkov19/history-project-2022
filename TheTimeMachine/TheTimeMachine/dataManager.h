#pragma once
#include "data.h"
class dataManager
{
	public:
		dataManager(ttm::theTimeMachine* ptr);
	public:
		ttm::theTimeMachine* lib;
		int year;
	public:
		void findEventByYear();

	private:
};

/*
LinkedList{};


vector<NODE> events;

for(NODE Event : events)
{
	cout << event << endl;
}
*/
#include "dataManager.h"

dataManager::dataManager(ttm::theTimeMachine* ptr)
{
	lib = ptr;
	year = std::stoi(lib->year);
}

void dataManager::findEventByYear()
{
	
}
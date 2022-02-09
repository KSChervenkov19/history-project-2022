#include "manager.h"

void ttm::theTimeMachine::findEventByYear()
{
	/*std::cout << mainProcess->year;
	intYear = std::stoi(mainProcess->year);
	mainProcess->year.clear();*/
	std::cout << "yeseyes";
}

void manager::cli(ttm::theTimeMachine* mainProcess)
{
	std::cout << mainProcess->info;
	ch = _getch();
	activate = (ch == '\r') ? true : false;
	if (activate)
	{
		std::cout << '\n';
		mainProcess->getLine();
		mainProcess->findEventByYear();
	}
	else
	{
		// insert panic logger here
	}
}
#include "manager.h"

void manager::cli(ttm::theTimeMachine* mainProcess)
{
	std::cout << mainProcess->info;
	ch = _getch();
	activate = (ch == '\r') ? true : false;
	if (activate)
	{
		std::cout << '\n';
		mainProcess->getLine();
	}
	else
	{
		// insert panic logger here
	}
}
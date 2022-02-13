#include "manager.h"

void manager::cli(ttm::theTimeMachine* mainProcess, data* linkedListData)
{
	linkedListData->createNodes();
	std::cout << mainProcess->info;
	ch = _getch();
	activate = (ch == '\r') ? true : false;
	if (activate)
	{
		std::cout << '\n';
		mainProcess->getLine(linkedListData);
	}
	else
	{
		// insert panic logger here
	}
}
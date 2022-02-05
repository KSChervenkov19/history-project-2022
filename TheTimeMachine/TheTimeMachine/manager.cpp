#include "manager.h"
ttd::theTimeMachine mainProcess;
void manager::cli()
{
	std::cout << mainProcess.info;
	ch = _getch();
	activate = (ch == '\r') ? true : false;
	if (activate)
	{
		std::cout << '\n';
		mainProcess.getLine();
	}
}
#include <iostream>
#include "manager.h"

int main()
{
    ttm::theTimeMachine* lib = new ttm::theTimeMachine;
    manager mainProcess;
    mainProcess.cli(lib);
    delete lib;
}
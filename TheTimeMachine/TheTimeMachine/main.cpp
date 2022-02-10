#include <iostream>
#include "manager.h"

int main()
{
    ttm::theTimeMachine* lib = new ttm::theTimeMachine;
    data* linkedListData = new data;
    manager mainProcess;
    mainProcess.cli(lib, linkedListData);
    delete lib;
    delete linkedListData;
}
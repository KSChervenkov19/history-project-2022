#pragma once
#include "data.h"
#include "lib.h"

class manager
{
	private:
		bool activate;
		char ch;

	public:
		void cli(ttm::theTimeMachine* mainProcess);
};
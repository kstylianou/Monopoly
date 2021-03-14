
#include <iostream>

#include "CManager.h"


using namespace std;

int main(int argc, char* argv[])
{
    auto* manager = new CManager();

	if(manager->SetGame())
	{
		manager->StartGame();
	}

	delete manager;
	
	_CrtDumpMemoryLeaks();

	
}


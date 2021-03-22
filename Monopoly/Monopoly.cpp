/*
 * Kyriakos Stylianou
 * kstylianou1@uclan.ac.uk
 * G20795768
 * 
 */


#include "CManager.h"

void StartGame()
{
	auto manager = make_shared<CManager>(); // Game manager
	
	if (manager->SetGame()) // Check if game is loaded correctly
	{
		manager->StartGame(); // Start game
	}
}

int main()
{
	// Load and start game
	StartGame();
	
	_CrtDumpMemoryLeaks(); // Check for memory leaks

	return 0;
}


#include "CManager.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;
// Manager constructor
CManager::CManager()
{
	this->square = new v_Square;
	this->player = new v_Player;
	this->state = STATE_RUNNING;
	this->round = 0;

	this->player_names.push_back(std::make_shared<std::string>("Dog"));
	this->player_names.push_back(std::make_shared<std::string>("Car"));
	/*this->player_names.push_back(std::make_shared<std::string>("Shoe"));
	this->player_names.push_back(std::make_shared<std::string>("Hat"));*/
}

// Manager destructor
CManager::~CManager()
{
	delete square;
	delete player;
}

// Load game method
bool CManager::SetGame()
{
	return (OpenSquareFile() && SetPlayers());
}

// Start game method
void CManager::StartGame()
{
	WelcomeMessage(); // Welcome message in console
	GetFirstPlayer();

	cout << "\nPlayer positions" << endl;
	for(int i = 0; i < player->size(); i++)
	{
		cout << player->at(playerSort[i])->GetName() << " plays " << i + 1 << endl;
		
	}

	UpdateRound();
	
}

void CManager::UpdateRound()
{
	while(this->state)
	{
		if (this->round == 20)
			this->state = STATE_FINISH;

		UpdateGame();

		this->round++;
	}
}

void CManager::UpdateGame()
{
	switch (this->state)
	{
	case STATE_RUNNING:
		for(int i = 0; i < PLAYERS_NUM; i++)
		{
			int playerRolls = player->at(playerSort[i])->roll();
			int playerPosition = player->at(playerSort[i])->MovePlayerPosition(playerRolls);
			square->at(playerPosition)->PlayerLands(player, playerSort[i], playerPosition);
		}
		break;
		
	case STATE_FINISH:
		break;
	}
}



 //Load squares from file
s_Squares CManager::SetSquares(std::string line)
{
	int code; // square code
	int cost; // Property cost
	int rent; // Property rent
	int colour; // Property Colour
	std::string name, second_name, third_name; // Square name
	std::stringstream ssin(line); // Line from monopoly file
	ssin >> code; // Assign code variable
	
	switch (code)
	{
	case 1: // When code is "1" Square is Property Square
		// Assign variables from file
		ssin >> name >> second_name >> cost >> rent >> colour;
		return make_shared<CProperty>(name + " " + second_name, code, cost, rent, colour);

	case 2: // When code is "2" Square is Go Square
		// Assign variables from file
		ssin >> name;
		return make_shared<CGo>(name, code);

	case 3: // When code is "3" Square is Station Square
		ssin >> name >> second_name;
		return  make_shared<CStations>(name + " " + second_name, code, 200, 10);

	case 4: // When code is "4" Square is Bonus Square
		ssin >> name;
		return make_shared<CBonus>(name, code);

	case 5: // When code is "5" Square is Penalty Square
		ssin >> name;
		return make_shared<CPenalty>(name, code);

	case 6: // When code is "6" Square is Jail Square
		ssin >> name;
		return make_shared<CJail>(name, code);

	case 7: // When code is "7" Square is Go to Jail Square
		ssin >> name >> second_name >> third_name;
		return make_shared<CGoToJail>(name + " " + second_name + " " + third_name, code);

	case 8: // When code is "8" Square is Parking Square
		ssin >> name >> second_name;
		return  make_shared<CParking>(name + " " + second_name, code);
		
	
	}


}

// Set players
bool CManager::SetPlayers()
{
	ifstream seed("seed.txt"); // Open seed file
	
	if (seed.is_open()) { // Check if seed file is open
		seed >> this->seed;
		for (int i = 0; i < player_names.size(); i++)
		{
			player->push_back(std::make_shared<CPlayer>(*player_names.at(i)));
		}
		// Close the file
		seed.close();
		return true;
	}

	cout << "No 'seed.txt' file found!" << endl;
	return false;
}

bool CManager::OpenSquareFile()
{
	string line;
	ifstream monopoly("monopoly.txt"); // Open monopoly file

	if (monopoly.is_open()) // Check if monopoly file is open
	{
		// Use a while loop together with the getline() function to read the file line by line
		while (getline(monopoly, line))
		{
			// Output the text from the file
			square->push_back(SetSquares(line)); // Push the new square
		}
		// Close the file
		monopoly.close();
		return true;
	}

	cout << "No 'monopoly.txt' file found!" << endl;
	return false;
}

void CManager::WelcomeMessage()
{
	cout << "Welcome to Monopol-ish" << endl;
}

void CManager::GetFirstPlayer()
{
	srand(seed);
	int nums[PLAYERS_NUM];
	for (int i = 0; i < PLAYERS_NUM; i++)
	{
		nums[i] = player->at(i)->roll();
		this->playerSort[i] = i;
	}


	for (int i = 0; i < PLAYERS_NUM - 1; i++)
	{
		for (int j = i + 1; j < PLAYERS_NUM; j++)
		{
			if (nums[i] < nums[j])
			{
				int tmp = this->playerSort[i];
				this->playerSort[i] = this->playerSort[j];
				this->playerSort[j] = tmp;

				int tmp1 = nums[i];
				nums[i] = nums[j];
				nums[j] = tmp1;
			}
		}
	}

}



#include "CManager.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;
// Manager constructor
CManager::CManager()
{
	this->square = make_shared<v_new_Square>();
	this->player = make_shared<v_newPlayer>();
	this->bank = make_unique<CBank>();
	this->state = STATE_RUNNING;
	this->round = 0;
	this->playersBankrupt = 0;

	this->player_names.push_back(std::make_shared<std::string>("Dog"));
	this->player_names.push_back(std::make_shared<std::string>("Car"));
	this->player_names.push_back(std::make_shared<std::string>("Shoe"));
	this->player_names.push_back(std::make_shared<std::string>("Hat"));
}

// Manager destructor
CManager::~CManager()
{

}

// Load game method
bool CManager::SetGame()
{
	// Return if all is set correctly
	return (OpenSquareFile() && SetPlayers());
}

// Start game method
void CManager::StartGame()
{
	WelcomeMessage(); // Welcome message in console
	
	UpdateRound(); // Update game for each round
	
}

// Update players round
void CManager::UpdateRound()
{
	// While the state is STATE_RUNNING
	while(this->state)
	{
		// Check if the players went bankrupt
		PlayersWentBankrupt();

		// Update game for each player
		UpdateGame();

		
		srand(this->seed);
		
		this->round++;
	}
}

// Update game for each player
void CManager::UpdateGame()
{
	
	switch (this->state)
	{
	case STATE_RUNNING:

		for(int i = 0; i < player->size(); i++)
		{
			cout << endl; // Empty line

			// Player roll dice
			int playerRolls = player->at(i)->roll();

			// Get position that player landed
			int playerPosition = player->at(i)->MovePlayerPosition(playerRolls);

			// Check if the player has negative money and property to mortgage
			bank->CheckPlayer(player->at(i), square);

			// Check if player has positive amount of money and can pay for mortgaged properties if any
			bank->PayMortgageProperty(player->at(i), square);

			// Check if player went bankrupt
			if (!player->at(i)->isPlaying()) {
				// Remove player from tha game
				player->erase(remove(player->begin(), player->end(), player->at(i)), player->end());
			
				this->playersBankrupt++;
				break;
			}

			// Player land on square after rolling dice
			square->at(playerPosition)->PlayerLands(player, i, playerPosition);
		}
		break;
		
	case STATE_FINISH:
		cout << "\nGame Over" << endl;

		// Get game winner
		GetWinner();
		
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

// Read file and load CSquare
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

// Display welcome message
void CManager::WelcomeMessage()
{
	cout << "Welcome to Monopol-ish" << endl;
}

// Get the winner with the highest money
void CManager::GetWinner()
{
	cout << "<" + player->at(0)->GetName() + ">" << " wins." << endl;
	cout << endl;
	cout << "Total rounds: " << round << endl;
	
}

// Check if 3 of the player went bankrupt to end the game
void CManager::PlayersWentBankrupt()
{
	if (this->playersBankrupt > 2)
	{
		this->state = STATE_FINISH;
	}
}



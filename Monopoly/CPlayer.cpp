/*
 * Kyriakos Stylianou
 * kstylianou1@uclan.ac.uk
 * G20795768
 *
 */

#include "CPlayer.h"
#include <iostream>

// Constructor
CPlayer::CPlayer(std::string name)
{
	colourSquares = make_unique<v_newInt>();
	playerOwns = make_unique<v_newInt>();
	mortgageProperties = make_unique<v_newInt>();
	playerStationOwns = make_unique<v_newInt>();
	
	this->name = name;
	this->position = 1;
	this->money = 1500;
	state = PLAYER_PLAYING;
}

// Destructor
CPlayer::~CPlayer()
{
	
}

// Player roll dice
int CPlayer::roll()
{
	int roll = static_cast<int>(static_cast<double> (rand()) / (RAND_MAX + 1) * 6.0f + 1); // Get the random number
	// Print the number tha player rolls
	cout << "<" + this->name + ">" << " rolls " << roll << endl;
	return roll;
}

// Change player position
int CPlayer::MovePlayerPosition(int roolNum)
{
	// If position is greater thank squares player continue from GO (index = 0)
	if (position + roolNum > SQUARES_NUM)
	{
		position = position + roolNum - SQUARES_NUM;
		PlayerPassesGo(); // Player passes go 
	}
	else
	{
		position = position + roolNum;
	}

	return position - 1;
}

// If player passes go gets 200
void CPlayer::PlayerPassesGo()
{
	money += 200; // Add 200 to player money
	
	// Print tha player passes go
	cout << "<" + name + ">" << " passes GO and collects " << static_cast<char>(156) << 200 << endl;
}

// When player buys new property
void CPlayer::PlayerOwnsNewProperty(int propertyIndex, int colour)
{
	// Push the square index
	playerOwns->push_back(propertyIndex);
	// Check if color is not null
	if (colour != NULL)
		colourSquares->push_back(colour); // Push the color number
}

// Check if player owns square
bool CPlayer::PlayerOwns(int propertyIndex)
{
	for (int playerOwn : *playerOwns) 
	{
		if (playerOwn == propertyIndex)
			return true;
	}

	return false;
}

// Check if player owns all from specific color code
bool CPlayer::PlayerOwnsAllColour(int colour)
{
	int count = 0;
	// Count variable to check how many of the same color Squares own
	for(int i = 0; i < colourSquares->size(); i++)
	{
		if (colourSquares->at(i) == colour) 
			count++;
	}

	// Return true if player owns all of the <colour> Squares
	switch (colour)
	{
	case 0:
		return (count == RED_COLOUR);
	case 1:
		return (count == GREY_COLOUR);
	case 2:
		return (count == BROWN_COLOUR);
	case 3:
		return (count == ORANGE_COLOUR);
	case 4:
		return (count == YELLOW_COLOUR);
	case 5:
		return (count == GREEN_COLOUR);
	case 6:
		return (count == BLUE_COLOUR);
	case 7:
		return (count == PURPLE_COLOUR);
	}
}

// Print player current money
void CPlayer::PrintMoney()
{
	cout << "<" + this->name + ">" << " has  " << static_cast<char>(156) << this->money << endl;
}

// Player went bankrupt
void CPlayer::PlayerBankrupt()
{
	playerOwns->clear(); // Clear player properties
	mortgageProperties->clear(); // Clear player mortgage properties
	playerStationOwns->clear(); // Clear player stations
	this->state = PLAYER_BANKRUPT; // Set player state to bankrupt
}




/*
 * Kyriakos Stylianou
 * kstylianou1@uclan.ac.uk
 * G20795768
 *
 */

#include "CSquare.h"

// Constructor
CSquare::CSquare(string name, int code)
{
	this->name = name;
	this->code = code;
}

// Destructor
CSquare::~CSquare()
{
}

// Player lands on <this> square
void CSquare::PlayerLands(s_Player players, int roundPlayerIndex, int squareIndex)
{
	// Print the square player landed
	PrintPlayerSquareLands(players->at(roundPlayerIndex)->GetName()); 

	// Print square unique message
	PrintSquareMessage(players, roundPlayerIndex, squareIndex);

	// Reword player buys or pays
	PlayerReword(players, roundPlayerIndex, squareIndex);

	// Print the player current money
	players->at(roundPlayerIndex)->PrintMoney();
}

// Reword player buys, pays, get bonus and penalty
void CSquare::PlayerReword(s_Player players, int roundPlayerIndex, int squareIndex)
{
	// Do nothing for this type of square
}

// Print square unique message
void CSquare::PrintSquareMessage(s_Player players, int roundPlayerIndex, int squareIndex)
{
	// Do nothing for this type of square
}

// Print the square player landed
void CSquare::PrintPlayerSquareLands(string name)
{
	cout << "<" + name + ">" << " lands on " << this->name << endl;
}

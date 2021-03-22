/*
 * Kyriakos Stylianou
 * kstylianou1@uclan.ac.uk
 * G20795768
 *
 */

#include "CGoToJail.h"

// Constructor
CGoToJail::CGoToJail(std::string name, int code) : CSquare(name, code)
{
}

// Destructor
CGoToJail::~CGoToJail()
{
}

// Print square unique message
void CGoToJail::PrintSquareMessage(s_Player players, int roundPlayerIndex, int squareIndex)
{
    cout << "<" + players->at(roundPlayerIndex)->GetName() + ">" << " goes to Jail" << endl;
   
}

// Player goes to jail and pays
void CGoToJail::PlayerReword(s_Player players, int roundPlayerIndex, int squareIndex)
{
	// Player goes to jail
    players->at(roundPlayerIndex)->SetPosition(7);

	// Player pays to get out of jail
    players->at(roundPlayerIndex)->SetMoney(players->at(roundPlayerIndex)->GetMoney() - 50);

	
    cout << "<" + players->at(roundPlayerIndex)->GetName() + ">" << " pays " << static_cast<char>(156) << "50" << endl;
}


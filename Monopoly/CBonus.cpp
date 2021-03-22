/*
 * Kyriakos Stylianou
 * kstylianou1@uclan.ac.uk
 * G20795768
 *
 */

#include "CBonus.h"

// Constructor
CBonus::CBonus(std::string names, int codes) : CSquare(names, codes)
{
	
}

// Destructor
CBonus::~CBonus()
{
}

// Player get bonus
void CBonus::PlayerReword(s_Player players, int roundPlayerIndex, int squareIndex)
{
	// Player roll dice and by the number gets a bonus
	switch (players->at(roundPlayerIndex)->roll())
	{
	case 1: // Player gets 20
		cout << "<" + players->at(roundPlayerIndex)->GetName() + ">" << " Find some money. Gain " << static_cast<char>(156) << 20 << endl;
		players->at(roundPlayerIndex)->SetMoney(players->at(roundPlayerIndex)->GetMoney() + 20);
		break;
		
	case 2: // Player gets 50
		cout << "<" + players->at(roundPlayerIndex)->GetName() + ">" << " Win coding competition. Gain " << static_cast<char>(156) << 50 << endl;
		players->at(roundPlayerIndex)->SetMoney(players->at(roundPlayerIndex)->GetMoney() + 50);
		break;
		
	case 3: // Player gets 100
		cout << "<" + players->at(roundPlayerIndex)->GetName() + ">" << " Received a rent rebate. Gain " << static_cast<char>(156) << 100 << endl;
		players->at(roundPlayerIndex)->SetMoney(players->at(roundPlayerIndex)->GetMoney() + 100);
		break;
		
	case 4: // Player gets 150
		cout << "<" + players->at(roundPlayerIndex)->GetName() + ">" << " Win the lottery. Gain " << static_cast<char>(156) << 150 << endl;
		players->at(roundPlayerIndex)->SetMoney(players->at(roundPlayerIndex)->GetMoney() + 150);
		break;
		
	case 5: // Player gets 200
		cout << "<" + players->at(roundPlayerIndex)->GetName() + ">" << " Received a bequest. Gain " << static_cast<char>(156) << 200 << endl;
		players->at(roundPlayerIndex)->SetMoney(players->at(roundPlayerIndex)->GetMoney() + 200);
		break;
		
	case 6: // Player gets 300
		cout << "<" + players->at(roundPlayerIndex)->GetName() + ">" << " It's your birthday. Gain " << static_cast<char>(156) << 300 << endl;
		players->at(roundPlayerIndex)->SetMoney(players->at(roundPlayerIndex)->GetMoney() + 300);
		break;
		
	default: ;
	}

}


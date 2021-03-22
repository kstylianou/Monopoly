/*
 * Kyriakos Stylianou
 * kstylianou1@uclan.ac.uk
 * G20795768
 *
 */

#include "CPenalty.h"

// Constructor
CPenalty::CPenalty(std::string name, int code) : CSquare(name, code)
{
}

// Destructor
CPenalty::~CPenalty()
{
}

// Player pays penalty
void CPenalty::PlayerReword(s_Player players, int roundPlayerIndex, int squareIndex)
{
	// Player roll dice and by the number gets pays penalty
	switch (players->at(roundPlayerIndex)->roll())
	{
	case 1: // Pays 20
		cout << "<" + players->at(roundPlayerIndex)->GetName() + ">" << " Buy a coffee in Starbucks. Lose " << static_cast<char>(156) << 20 << endl;
		players->at(roundPlayerIndex)->SetMoney(players->at(roundPlayerIndex)->GetMoney() - 20);
		break;
		
	case 2: // Pays 50
		cout << "<" + players->at(roundPlayerIndex)->GetName() + ">" << " Pay your broadband bill. Lose " << static_cast<char>(156) << 50 << endl;
		players->at(roundPlayerIndex)->SetMoney(players->at(roundPlayerIndex)->GetMoney() - 50);
		break;
		
	case 3: // Pays 100
		cout << "<" + players->at(roundPlayerIndex)->GetName() + ">" << " Visit the SU shop for food. Lose " << static_cast<char>(156) << 100 << endl;
		players->at(roundPlayerIndex)->SetMoney(players->at(roundPlayerIndex)->GetMoney() - 100);
		break;
		
	case 4: // Pays 150
		cout << "<" + players->at(roundPlayerIndex)->GetName() + ">" << " Buy an assignment solution. Lose " << static_cast<char>(156) << 150 << endl;
		players->at(roundPlayerIndex)->SetMoney(players->at(roundPlayerIndex)->GetMoney() - 150);
		break;
		
	case 5: // Pays 200
		cout << "<" + players->at(roundPlayerIndex)->GetName() + ">" << " Go for a romantic meal. Lose " << static_cast<char>(156) << 200 << endl;
		players->at(roundPlayerIndex)->SetMoney(players->at(roundPlayerIndex)->GetMoney() - 200);
		break;
		
	case 6: // Pays 300
		cout << "<" + players->at(roundPlayerIndex)->GetName() + ">" << " Pay some university fees. Lose " << static_cast<char>(156) << 300 << endl;
		players->at(roundPlayerIndex)->SetMoney(players->at(roundPlayerIndex)->GetMoney() - 300);
		break;
	}
}


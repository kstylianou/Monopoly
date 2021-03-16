#include "CPenalty.h"

CPenalty::CPenalty(std::string name, int code) : CSquare(name, code)
{
}

void CPenalty::PlayerReword(s_Player players, int roundPlayerIndex, int squareIndex)
{
	switch (players->at(roundPlayerIndex)->roll())
	{
	case 1:
		cout << "<" + players->at(roundPlayerIndex)->GetName() + ">" << " Buy a coffee in Starbucks. Lose " << static_cast<char>(156) << 20 << endl;
		players->at(roundPlayerIndex)->SetMoney(players->at(roundPlayerIndex)->GetMoney() - 20);
		break;
	case 2:
		cout << "<" + players->at(roundPlayerIndex)->GetName() + ">" << " Pay your broadband bill. Lose " << static_cast<char>(156) << 50 << endl;
		players->at(roundPlayerIndex)->SetMoney(players->at(roundPlayerIndex)->GetMoney() - 50);
		break;
	case 3:
		cout << "<" + players->at(roundPlayerIndex)->GetName() + ">" << " Visit the SU shop for food. Lose " << static_cast<char>(156) << 100 << endl;
		players->at(roundPlayerIndex)->SetMoney(players->at(roundPlayerIndex)->GetMoney() - 100);
		break;
	case 4:
		cout << "<" + players->at(roundPlayerIndex)->GetName() + ">" << " Buy an assignment solution. Lose " << static_cast<char>(156) << 150 << endl;
		players->at(roundPlayerIndex)->SetMoney(players->at(roundPlayerIndex)->GetMoney() - 150);
		break;
	case 5:
		cout << "<" + players->at(roundPlayerIndex)->GetName() + ">" << " Go for a romantic meal. Lose " << static_cast<char>(156) << 200 << endl;
		players->at(roundPlayerIndex)->SetMoney(players->at(roundPlayerIndex)->GetMoney() - 200);
		break;
	case 6:
		cout << "<" + players->at(roundPlayerIndex)->GetName() + ">" << " Pay some university fees. Lose " << static_cast<char>(156) << 300 << endl;
		players->at(roundPlayerIndex)->SetMoney(players->at(roundPlayerIndex)->GetMoney() - 300);
		break;
	}
}


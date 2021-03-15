#include "CPenalty.h"

CPenalty::CPenalty(std::string name, int code) : CSquare(name, code)
{
}

void CPenalty::PlayerLands(s_Player players, int roundPlayerIndex, int squareIndex)
{
	cout << "<" + players->at(roundPlayerIndex)->GetName() + ">" << " lands on " << this->GetName() << endl;

	PlayerReword(players, roundPlayerIndex, squareIndex);

	cout << "<" + players->at(roundPlayerIndex)->GetName() + ">" << " has  " << static_cast<char>(156) << players->at(roundPlayerIndex)->GetMoney() << endl;
}


void CPenalty::PlayerReword(s_Player players, int roundPlayerIndex, int squareIndex)
{
	switch (players->at(roundPlayerIndex)->roll())
	{
	case 1:
		cout << "Buy a coffee in Starbucks. Lose 20" << endl;
		players->at(roundPlayerIndex)->SetMoney(players->at(roundPlayerIndex)->GetMoney() - 20);
		break;
	case 2:
		cout << "Pay your broadband bill. Lose 50" << endl;
		players->at(roundPlayerIndex)->SetMoney(players->at(roundPlayerIndex)->GetMoney() - 50);
		break;
	case 3:
		cout << "Visit the SU shop for food. Lose 100" << endl;
		players->at(roundPlayerIndex)->SetMoney(players->at(roundPlayerIndex)->GetMoney() - 100);
		break;
	case 4:
		cout << "Buy an assignment solution. Lose 150" << endl;
		players->at(roundPlayerIndex)->SetMoney(players->at(roundPlayerIndex)->GetMoney() - 150);
		break;
	case 5:
		cout << "Go for a romantic meal. Lose 200" << endl;
		players->at(roundPlayerIndex)->SetMoney(players->at(roundPlayerIndex)->GetMoney() - 200);
		break;
	case 6:
		cout << "Pay some university fees. Lose 300" << endl;
		players->at(roundPlayerIndex)->SetMoney(players->at(roundPlayerIndex)->GetMoney() - 300);
		break;
	}
}


#include "CBonus.h"
CBonus::CBonus(std::string names, int codes) : CSquare(names, codes)
{
	
}

void CBonus::PlayerLands(s_Player players, int roundPlayerIndex, int squareIndex)
{
	cout << "<" + players->at(roundPlayerIndex)->GetName() + ">" << " lands on " << this->GetName() << endl;

	PlayerReword(players, roundPlayerIndex, squareIndex);

	cout << "<" + players->at(roundPlayerIndex)->GetName() + ">" << " has  " << static_cast<char>(156) << players->at(roundPlayerIndex)->GetMoney() << endl;
}


void CBonus::PlayerReword(s_Player players, int roundPlayerIndex, int squareIndex)
{
	switch (players->at(roundPlayerIndex)->roll())
	{
	case 1:
		cout << "Find some money. Gain 20" << endl;
		players->at(roundPlayerIndex)->SetMoney(players->at(roundPlayerIndex)->GetMoney() + 20);
		break;
	case 2:
		cout << "Win coding competition. Gain 50" << endl;
		players->at(roundPlayerIndex)->SetMoney(players->at(roundPlayerIndex)->GetMoney() + 50);
		break;
	case 3:
		cout << "Received a rent rebate. Gain 100" << endl;
		players->at(roundPlayerIndex)->SetMoney(players->at(roundPlayerIndex)->GetMoney() + 100);
		break;
	case 4:
		cout << "Win the lottery. Gain 150" << endl;
		players->at(roundPlayerIndex)->SetMoney(players->at(roundPlayerIndex)->GetMoney() + 150);
		break;
	case 5:
		cout << "Received a bequest. Gain 200" << endl;
		players->at(roundPlayerIndex)->SetMoney(players->at(roundPlayerIndex)->GetMoney() + 200);
		break;
	case 6:
		cout << "It's your birthday. Gain 300" << endl;
		players->at(roundPlayerIndex)->SetMoney(players->at(roundPlayerIndex)->GetMoney() + 300);
		break;
	}

}


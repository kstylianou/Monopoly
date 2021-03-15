#include "CStations.h"

CStations::CStations(std::string name, int code, int cost, int ticket) : CSquare(name, code)
{
	this->cost = cost;
	this->ticket = ticket;
	this->isOwned = false;
}

void CStations::PlayerReword(s_Player players, int roundPlayerIndex, int squareIndex)
{
	if (!this->isOwned)
	{
		if (players->at(roundPlayerIndex)->GetMoney() > 0)
		{
			players->at(roundPlayerIndex)->SetMoney(players->at(roundPlayerIndex)->GetMoney() - this->cost);
			players->at(roundPlayerIndex)->PlayerOwnsNewProperty(squareIndex, NULL);

			this->isOwned = true;

			cout << "<" + players->at(roundPlayerIndex)->GetName() + ">" << " buys " << this->GetName() << " for " << static_cast<char>(156) << this->cost << endl;
		}
	}
	else
	{
		for (int i = 0; i < players->size(); i++)
		{
			if (players->at(i)->PlayerOwns(squareIndex) && i != roundPlayerIndex)
			{
				players->at(roundPlayerIndex)->SetMoney(players->at(roundPlayerIndex)->GetMoney() - this->ticket);
				players->at(i)->SetMoney(players->at(i)->GetMoney() + this->ticket);

				cout << "<" + players->at(roundPlayerIndex)->GetName() + ">" << " pays " << static_cast<char>(156) << this->ticket << " for ticket" << endl;
			}
		}
	}
}


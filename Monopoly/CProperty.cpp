#include "CProperty.h"

CProperty::CProperty(string name, int code, int cost, int rent, int colour) : CSquare(name, code)
{
	this->cost = cost;
	this->rent = rent;
	this->colour = colour;
	this->isOwned = false;
}

void CProperty::PlayerReword(s_Player players, int roundPlayerIndex, int squareIndex)
{
	if(!this->isOwned)
	{
		if (players->at(roundPlayerIndex)->GetMoney() > 0)
		{
			players->at(roundPlayerIndex)->SetMoney(players->at(roundPlayerIndex)->GetMoney() - this->cost);
			players->at(roundPlayerIndex)->PlayerOwnsNewProperty(squareIndex, this->colour);

			if (players->at(roundPlayerIndex)->PlayerOwnsAllColour(colour))
			{
				rent *= 2;
			}

			this->isOwned = true;

			cout << "<" + players->at(roundPlayerIndex)->GetName() + ">" << " buys " << this->GetName() << " for " << static_cast<char>(156) << this->cost << endl;
		}
	}else
	{
		for(int i = 0; i < players->size(); i++)
		{
			if(players->at(i)->PlayerOwns(squareIndex) && i != roundPlayerIndex)
			{
				players->at(roundPlayerIndex)->SetMoney(players->at(roundPlayerIndex)->GetMoney() - this->rent);
				players->at(i)->SetMoney(players->at(i)->GetMoney() + this->rent);

				cout << "<" + players->at(roundPlayerIndex)->GetName() + ">" << " pays " << static_cast<char>(156) << this->rent << endl;
			}
		}
	}
}


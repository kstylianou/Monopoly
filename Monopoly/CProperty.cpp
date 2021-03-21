#include "CProperty.h"

// Constructor
CProperty::CProperty(string name, int code, int cost, int rent, int colour) : CSquare(name, code)
{
	this->cost = cost;
	this->rent = rent;
	this->colour = colour;
}

// Destructor
CProperty::~CProperty()
{
}

// Player buys or pays rent
void CProperty::PlayerReword(s_Player players, int roundPlayerIndex, int squareIndex)
{
	// Check if the property is owned by player
	if(this->CheckIfPropertyIsOwned(players, squareIndex))
	{
		// Check if the money is above 0
		if (players->at(roundPlayerIndex)->GetMoney() > 0)
		{
			this->PlayerBuysProperty(players, roundPlayerIndex, squareIndex); // Player buys property
		}
	}else
	{
		this->PlayerPaysRent(players, roundPlayerIndex, squareIndex); // Player pays rent
	}
}

// Check if the property is owned by player
bool CProperty::CheckIfPropertyIsOwned(s_Player players, int squareIndex)
{
	for (int i = 0; i < players->size(); i++)
	{
		if (players->at(i)->CheckIfPlayerOwnsProperty(squareIndex))
		{
			return false;
		}
	}

	return true;
}

// Player buys <this> property
void CProperty::PlayerBuysProperty(s_Player players, int roundPlayerIndex, int squareIndex)
{
	// Get players money
	players->at(roundPlayerIndex)->SetMoney(players->at(roundPlayerIndex)->GetMoney() - this->cost);

	// Add player owns property index
	players->at(roundPlayerIndex)->PlayerOwnsNewProperty(squareIndex, this->colour);

	// Print player buys <property> 
	cout << "<" + players->at(roundPlayerIndex)->GetName() + ">" << " buys " << this->GetName() << " for " << static_cast<char>(156) << this->cost << endl;
}

// Player who landed in this property square pays rent
void CProperty::PlayerPaysRent(s_Player players, int roundPlayerIndex, int squareIndex)
{
	for (int i = 0; i < players->size(); i++)
	{
		// Check who is the owner and if the property is not mortgage
		if (players->at(i)->PlayerOwns(squareIndex) && !players->at(i)->CheckIfPropertyIsMortgageBySquare(squareIndex))
		{
			int payRent = this->rent;

			// If player owns all <colour> square. Rent is doubled
			if (players->at(i)->PlayerOwnsAllColour(colour))
				payRent *= 2;
			
			
			// Player who landed in <this> property square pays the owner rent
			players->at(roundPlayerIndex)->SetMoney(players->at(roundPlayerIndex)->GetMoney() - payRent);

			// Owner gets the rent
			players->at(i)->SetMoney(players->at(i)->GetMoney() + payRent);

			// Print player pays rent
			cout << "<" + players->at(roundPlayerIndex)->GetName() + ">" << " pays " << static_cast<char>(156) << payRent << " to " << players->at(i)->GetName() << endl;
		}
	}
}



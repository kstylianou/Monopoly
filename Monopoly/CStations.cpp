#include "CStations.h"

// Constructor
CStations::CStations(std::string name, int code, int cost, int ticket) : CSquare(name, code)
{
	this->cost = cost;
	this->ticket = ticket;
}

// Destructor
CStations::~CStations()
= default;

// Player buys or pays rent
void CStations::PlayerReword(s_Player players, int roundPlayerIndex, int squareIndex)
{
	// Check if the property is owned by player
	if (CheckIfPropertyIsOwned(players, squareIndex))
	{
		// Check if the money is above 0
		if (players->at(roundPlayerIndex)->GetMoney() > 0)
		{
			this->PlayerBuysProperty(players, roundPlayerIndex, squareIndex); // Player buys property
		}
	}
	else
	{
		this->PlayerPaysRent(players, roundPlayerIndex, squareIndex); // Player pays rent
		
	}
}

// Get cost
int CStations::GetCost()
{
	return this->cost;
}

// Check if the property is owned by player
auto CStations::CheckIfPropertyIsOwned(const s_Player& players, int squareIndex) -> bool
{
	for (auto& i : *players) 
	{
		if (i->GetPlayerOwnsStation(squareIndex))
		{
			return false;
		}
	}

	return true;
}

// Player buys <this> Station
void CStations::PlayerBuysProperty(s_Player players, int roundPlayerIndex, int squareIndex)
{
	// Get players money
	players->at(roundPlayerIndex)->SetMoney(players->at(roundPlayerIndex)->GetMoney() - this->cost);

	// Add player owns property index
	players->at(roundPlayerIndex)->PlayerOwnsStation(squareIndex);

	// Print player buys <station> 
	cout << "<" + players->at(roundPlayerIndex)->GetName() + ">" << " buys " << this->GetName() << " for " << static_cast<char>(156) << this->cost << endl;
}


// Player who landed in this station square pays rent
void CStations::PlayerPaysRent(const s_Player& players, int roundPlayerIndex, int squareIndex) const
{
	for (int i = 0; i < players->size(); i++)
	{
		// Check who is the owner and if the station is not mortgage
		if (players->at(i)->PlayerOwns(squareIndex) && i != roundPlayerIndex)
		{
			// Player who landed in <this> station square pays the owner rent
			players->at(roundPlayerIndex)->SetMoney(players->at(roundPlayerIndex)->GetMoney() - this->ticket);

			// Owner gets the rent
			players->at(i)->SetMoney(players->at(i)->GetMoney() + this->ticket);

			// Print player pays rent
			cout << "<" + players->at(roundPlayerIndex)->GetName() + ">" << " pays " << static_cast<char>(156) << this->ticket << " for ticket" << endl;
		}
	}
}


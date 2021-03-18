#include "CBank.h"

#include "CProperty.h"

// Constructor
CBank::CBank()
{
}

// Destructor
CBank::~CBank()
{
}

// Check player if has negative money and owned properties to mortgage
void CBank::CheckPlayer(shared_ptr<CPlayer> player, v_Square squares)
{
	// Check if player has negative money and still playing
	while(player->PlayerHasNegativeMoney() && player->isPlaying())
	{
		// Check if player has any properties and if not all properties has mortgage
		if (player->OwnPropertyLength() > player->GetMortgageLength()) {

			// Square index for the lowest valued property
			int squareIndex = 0; 

			// Get the minimum property valued
			if (GetMinPropertyCost(player, squares, squareIndex) != -1) {

				// Mortgage <this> property
				MortgagePlayerProperty(player, squares, squareIndex);
			}
			else
			{
				// Break the while loop
				break;
			}
		}else
		{
			// Player is bankrupt
			player->PlayerBankrupt();

			cout << "<" + player->GetName() + ">" << " went bankrupt" << endl;
		}
	}

	
}

// Bank get the mortgage the property and pays the value of the property 
void CBank::MortgagePlayerProperty(shared_ptr<CPlayer> player, v_Square squares, int squareIndex)
{
	// Add to the player the mortgage property index
	player->PlayerMortgage(squareIndex);

	// Print that bank mortgage property
	cout << "<" + player->GetName() + ">" << " mortgage " << squares->at(squareIndex)->GetName() << " for " << static_pointer_cast<CProperty>(squares->at(squareIndex))->GetCost() << endl;

	// Set the value of the property to the player money
	player->SetMoney(player->GetMoney() + squares->at(squareIndex)->GetCost());
}

// Player pays for mortgaged properties
void CBank::PayMortgageProperty(shared_ptr<CPlayer> player, v_Square squares)
{
	// Check if player has any mortgaged properties
	if (player->GetMortgageLength() > 0)
	{
		// Go through all mortgaged properties
		for (int i = 0; i < player->GetMortgageLength(); i++)
		{
			// Check If player has enough money to repay for the mortgaged property
			if (player->GetMoney() > squares->at(player->GetMortgageByIndex(i))->GetCost())
			{
				// Get the money from the player
				player->SetMoney(player->GetMoney() - squares->at(player->GetMortgageByIndex(i))->GetCost());

				// Print that player repay for his mortgaged property
				cout << "<" + player->GetName() + ">" << " repay mortgaged " << squares->at(player->GetMortgageByIndex(i))->GetName() << " for " << squares->at(player->GetMortgageByIndex(i))->GetCost() << endl;

				// Remove the mortgaged property
				player->PlayerPaysMortagePropery(player->GetMortgageByIndex(i));

			}
		}

	}
}

// Get the lowest valued property that player owns
int CBank::GetMinPropertyCost(shared_ptr<CPlayer> player, v_Square squares, int& index)
{
	// index of 0 can be mortgage property so i have to use dummy number to check for the lowest valued property if any
	int min = 1000;

	// Check if the index 0 is not mortgage property
	if (!player->CheckIfPropertyIsMortgage(0))
	{
		// Min is the first valued property for now
		min = squares->at(player->GetOwnPropertyByIndex(0))->GetCost();
		// Index for the lowest is the 0 for now
		index = player->GetOwnPropertyByIndex(0);
	}
	
	for (int i = 1; i < player->OwnPropertyLength(); i++)
	{
		// Check if the property cost is less than "min" and if the property of "i" is not mortgage
		if (squares->at(player->GetOwnPropertyByIndex(i))->GetCost() < min && !player->CheckIfPropertyIsMortgage(i))
		{
			// min valued property
			min = squares->at(player->GetOwnPropertyByIndex(i))->GetCost();
			// Property index
			index = player->GetOwnPropertyByIndex(i);
		}
	}

	// Check if the min is not the dummy number
	if (min != 1000)
		return min;

	// if not property found return -1
	return -1;
}

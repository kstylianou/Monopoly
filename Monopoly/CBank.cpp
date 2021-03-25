/*
 * Kyriakos Stylianou
 * kstylianou1@uclan.ac.uk
 * G20795768
 *
 */

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
	while(player->GetMoney() < 0 && player->isPlaying())
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

			cout << "\n<" + player->GetName() + ">" << " went bankrupt" << endl;
		}
	}

	
}

// Bank get the mortgage the property and pays the value of the property 
void CBank::MortgagePlayerProperty(shared_ptr<CPlayer> player, v_Square squares, int squareIndex)
{
	// Add to the player the mortgage property index
	player->SetPlayerMortgage(squareIndex);

	// Get Property cost
	int propertyCost = static_pointer_cast<CProperty>(squares->at(squareIndex))->GetCost();

	// Print that bank mortgage property
	cout << "<" + player->GetName() + ">" << " mortgage " << squares->at(squareIndex)->GetName() << " for " << POUND << propertyCost << endl;

	// Set the value of the property to the player money
	player->SetMoney(player->GetMoney() + propertyCost);
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
			// Get Property cost
			const int propertyCost = static_pointer_cast<CProperty>(squares->at(player->GetMortgageByIndex(i)))->GetCost(); 
			
			// Check If player has enough money to repay for the mortgaged property
			if (player->GetMoney() > propertyCost)
			{
				// Get the money from the player
				player->SetMoney(player->GetMoney() - propertyCost);

				// Print that player repay for his mortgaged property
				cout << "<" + player->GetName() + ">" << " repay mortgaged " << squares->at(player->GetMortgageByIndex(i))->GetName() << " for " << POUND << propertyCost << endl;

				// Remove the mortgaged property
				player->PlayerPaysMortgageProperty(player->GetMortgageByIndex(i));

			}
		}

	}
}

// Get the lowest valued property that player owns
int CBank::GetMinPropertyCost(shared_ptr<CPlayer> player, v_Square squares, int& index)
{
	int min = -1;

	// Get the first non mortgaged property
	for(int i = 0; i < player->OwnPropertyLength(); i++)
	{
		if(!player->CheckIfPropertyIsMortgage(i))
		{
			// Min is the first owned property
			min = static_pointer_cast<CProperty>(squares->at(player->GetOwnPropertyByIndex(i)))->GetCost();

			// Index for the lowest 
			index = player->GetOwnPropertyByIndex(i);

			break;
		}
	}
	
	for (int i = 1; i < player->OwnPropertyLength(); i++)
	{
		// Check if the property cost is less than "min" and if the property of "i" is not mortgage
		if (static_pointer_cast<CProperty>(squares->at(player->GetOwnPropertyByIndex(i)))->GetCost() < min && !player->CheckIfPropertyIsMortgage(i))
		{
			// min valued property
			min = static_pointer_cast<CProperty>(squares->at(player->GetOwnPropertyByIndex(i)))->GetCost();
			// Property index
			index = player->GetOwnPropertyByIndex(i);
		}
	}

	
	return min;
}

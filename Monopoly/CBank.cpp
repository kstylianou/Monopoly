#include "CBank.h"

void CBank::CheckPlayer(shared_ptr<CPlayer> player, v_Square* squares)
{

	while(player->PlayerHasNegativeMoney() && player->isPlaying())
	{
		if (player->OwnPropertyLength() > player->GetMortgageLength()) {
			int squareIndex = 0;
			if (GetMinPropertyCost(player, squares, squareIndex) != -1) {

				MortgagePlayerProperty(player, squares, squareIndex);

				player->PlayerMortgage(squareIndex);

				cout << player->GetName() << " mortgage " << squares->at(squareIndex)->GetName() << endl;

				player->SetMoney(player->GetMoney() + squares->at(squareIndex)->GetCost());
				
			}else
			{
				break;
			}
		}else
		{
			player->PlayerBankrupt();
			
			cout << "Bankrupt" << endl;
		}
	}

	
}

void CBank::MortgagePlayerProperty(shared_ptr<CPlayer> player, v_Square* squares, int squareIndex)
{
	
}

void CBank::PayMortgageProperty(shared_ptr<CPlayer> player, v_Square* squares)
{
	if (player->GetMortgageLength() > 0)
	{

		for (int i = 0; i < player->GetMortgageLength(); i++)
		{
			if (player->GetMoney() > squares->at(player->GetMortgageByIndex(i))->GetCost())
			{
				player->SetMoney(player->GetMoney() - squares->at(player->GetMortgageByIndex(i))->GetCost());
				cout << player->GetName() << " pays debt " << squares->at(player->GetMortgageByIndex(i))->GetCost() << endl;
				player->PlayerPaysMortagePropery(player->GetMortgageByIndex(i));

			}
		}

	}
}

int CBank::GetMinPropertyCost(shared_ptr<CPlayer> player, v_Square* squares, int& index)
{
	int min = -1;
	bool check = false;
	if (!player->CheckIfPropertyIsMortgage(0))
	{
		min = squares->at(player->GetOwnPropertyByIndex(0))->GetCost();
		index = player->GetOwnPropertyByIndex(0);
		check = true;
	}
	else
	{
		min = 1000;
	}

	for (int i = 1; i < player->OwnPropertyLength(); i++)
	{
		if (squares->at(player->GetOwnPropertyByIndex(i))->GetCost() < min && !player->CheckIfPropertyIsMortgage(i))
		{
			min = squares->at(player->GetOwnPropertyByIndex(i))->GetCost();
			index = player->GetOwnPropertyByIndex(i);
			check = true;
		}
	}
	if (check == true)
		return min;
	else
		return -1;

}

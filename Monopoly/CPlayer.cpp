#include "CPlayer.h"

#include <iostream>

CPlayer::CPlayer(std::string name)
{
	colourSquares = new v_int;
	playerOwns = new v_int;
	mortgageProperties = new v_int;
	this->name = name;
	this->position = 1;
	this->money = 1500;
	state = PLAYER_PLAYING;
}

CPlayer::~CPlayer()
{
	delete playerOwns;
	delete colourSquares;
	delete mortgageProperties;
}

int CPlayer::roll()
{
	int roll = static_cast<int>(static_cast<double> (rand()) / (RAND_MAX + 1) * 6.0f + 1);
	cout << "<" + this->name + ">" << " rolls " << roll << endl;
	return roll;
}

int CPlayer::MovePlayerPosition(int roolNum)
{
	if (position + roolNum > SQUARES_NUM)
	{
		position = position + roolNum - SQUARES_NUM;
		PlayerPassesGo();
	}
	else
	{
		position = position + roolNum;
	}

	return position - 1;
}

void CPlayer::PlayerPassesGo()
{
	money += 200;
	cout << "<" + name + ">" << " passes GO and collects " << static_cast<char>(156) << 200 << endl;
}

void CPlayer::PlayerOwnsNewProperty(int propertyIndex, int colour)
{
	playerOwns->push_back(propertyIndex);
	if (colour != NULL)
		colourSquares->push_back(colour);
}

bool CPlayer::PlayerOwns(int propertyIndex)
{
	for (int playerOwn : *playerOwns) 
	{
		if (playerOwn == propertyIndex)
			return true;
	}

	return false;
}

bool CPlayer::PlayerOwnsAllColour(int colour)
{
	int count = 0;
	for(int i = 0; i < colourSquares->size(); i++)
	{
		if (colourSquares->at(i) == colour)
			count++;
	}
	
	switch (colour)
	{
	case 0:
		return (count == RED_COLOUR);
	case 1:
		return (count == GREY_COLOUR);
	case 2:
		return (count == BROWN_COLOUR);
	case 3:
		return (count == ORANGE_COLOUR);
	case 4:
		return (count == YELLOW_COLOUR);
	case 5:
		return (count == GREEN_COLOUR);
	case 6:
		return (count == BLUE_COLOUR);
	case 7:
		return (count == PURPLE_COLOUR);
	}
}

void CPlayer::PrintMoney()
{
	cout << "<" + this->name + ">" << " has  " << static_cast<char>(156) << this->money << endl;
}

void CPlayer::PlayerMortgage(int squareIndex)
{
	mortgageProperties->push_back(squareIndex);
}

bool CPlayer::CheckIfPlayerOwnsProperty(int index)
{
	return (count(playerOwns->begin(), playerOwns->end(), index));
}

bool CPlayer::CheckIfPropertyIsMortgage(int index)
{
	return (count(mortgageProperties->begin(), mortgageProperties->end(), playerOwns->at(index)));
}

bool CPlayer::CheckIfPropertyIsMortgageBySquare(int index)
{
	if (mortgageProperties->size() > 0) {
		return (count(mortgageProperties->begin(), mortgageProperties->end(), index));
	}
}

bool CPlayer::PlayerHasMortgageProperty()
{
	return (!mortgageProperties->empty());
}

void CPlayer::PlayerPaysMortagePropery(int squareIndex)
{
	mortgageProperties->erase(remove(mortgageProperties->begin(), mortgageProperties->end(), squareIndex), mortgageProperties->end());
}

int CPlayer::GetMortgageByIndex(int index)
{
	return mortgageProperties->at(index);
}

int CPlayer::GetMortgageLength()
{
	return mortgageProperties->size();
}

bool CPlayer::PlayerHasNegativeMoney()
{
	return (this->money < 0);
}

int CPlayer::GetOwnPropertyByIndex(int index)
{
	return playerOwns->at(index);
}

bool CPlayer::isPlaying()
{
	return this->state;
}

void CPlayer::PlayerBankrupt()
{
	playerOwns->clear();
	mortgageProperties->clear();
	this->state = PLAYER_BANKRUPT;
}




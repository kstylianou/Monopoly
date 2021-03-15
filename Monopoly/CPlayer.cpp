#include "CPlayer.h"

#include <iostream>

CPlayer::CPlayer(std::string name)
{
	colourSquares = new v_PlayerOwns;
	playerOwns = new v_PlayerOwns;
	this->name = name;
	this->position = 1;
	this->money = 1500;
}

CPlayer::~CPlayer()
{
	delete playerOwns;
	delete colourSquares;
}

int CPlayer::roll()
{
	int roll = static_cast<int>(static_cast<double> (rand()) / (RAND_MAX + 1) * 6.0f + 1);
	cout << "\n<" + this->name + ">" << " rolls " << roll << endl;
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

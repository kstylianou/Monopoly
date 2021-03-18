#pragma once
#include "CPlayer.h"
#include "CSquare.h"
typedef std::vector<std::shared_ptr<CSquare>> v_Square;
class CBank
{
public:
	CBank() {};

	void CheckPlayer(shared_ptr<CPlayer> player, v_Square* squares);
	void MortgagePlayerProperty(shared_ptr<CPlayer> player, v_Square* squares, int squareIndex);
	void PayMortgageProperty(shared_ptr<CPlayer> player, v_Square* squares);
	int GetMinPropertyCost(shared_ptr<CPlayer> player, v_Square* squares, int& index);
};


#pragma once
#include "CSquare.h"


class CBonus : public CSquare
{
public:
	CBonus(string name, int code);

	void PlayerLands(s_Player players, int roundPlayerIndex, int squareIndex) override;
	void PlayerReword(s_Player players, int roundPlayerIndex, int squareIndex) override;
};


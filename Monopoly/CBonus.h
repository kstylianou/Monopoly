#pragma once
#include "CSquare.h"


class CBonus : public CSquare
{
public:
	CBonus(string name, int code);

	void PlayerReword(s_Player players, int roundPlayerIndex, int squareIndex) override;
};


#pragma once
#include "CSquare.h"

class CJail : public CSquare
{
public:
	CJail(std::string name, int code);

	void PlayerLands(s_Player players, int roundPlayerIndex, int squareIndex) override;
};


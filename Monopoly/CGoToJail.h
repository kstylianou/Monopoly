#pragma once
#include "CSquare.h"

class CGoToJail : public CSquare
{
public:
	CGoToJail(std::string name, int code);

	void PlayerLands(s_Player players, int roundPlayerIndex, int squareIndex) override;
	void PlayerReword(s_Player players, int roundPlayerIndex, int squareIndex) override;
};


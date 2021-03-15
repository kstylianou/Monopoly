#pragma once
#include "CSquare.h"

class CPenalty : public CSquare
{
public:
	CPenalty(std::string name, int code);

	void PlayerLands(s_Player players, int roundPlayerIndex, int squareIndex) override;
	void PlayerReword(s_Player players, int roundPlayerIndex, int squareIndex) override;
};


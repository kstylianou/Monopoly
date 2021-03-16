#pragma once
#include "CSquare.h"

class CGoToJail : public CSquare
{
public:
	CGoToJail(std::string name, int code);

	void PrintSquareMessage(s_Player players, int roundPlayerIndex, int squareIndex) override;
	void PlayerReword(s_Player players, int roundPlayerIndex, int squareIndex) override;
};


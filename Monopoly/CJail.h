#pragma once
#include "CSquare.h"

class CJail : public CSquare
{
public:
	CJail(std::string name, int code);

	void PrintSquareMessage(s_Player players, int roundPlayerIndex, int squareIndex) override;
};


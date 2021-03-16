#pragma once
#include "CSquare.h"

class CParking : public CSquare
{
public:
	CParking(string square_name, int square_code);

	void PrintSquareMessage(s_Player players, int roundPlayerIndex, int squareIndex) override;
};


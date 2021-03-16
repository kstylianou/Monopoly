#pragma once
#include "CSquare.h"

class CPenalty : public CSquare
{
public:
	CPenalty(std::string name, int code);
	
	void PlayerReword(s_Player players, int roundPlayerIndex, int squareIndex) override;
};


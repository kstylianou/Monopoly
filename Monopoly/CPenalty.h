#pragma once
#include "CSquare.h"

class CPenalty : public CSquare
{
public:
	// Constructor
	CPenalty(std::string name, int code);

	// Destructor
	~CPenalty();

	// Player gets penalty
	void PlayerReword(s_Player players, int roundPlayerIndex, int squareIndex) override;
};


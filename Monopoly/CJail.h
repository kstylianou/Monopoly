#pragma once
#include "CSquare.h"

class CJail : public CSquare
{
public:
	// Constructor
	CJail(std::string name, int code);

	// Destructor
	~CJail();

	// Print square unique message 
	void PrintSquareMessage(s_Player players, int roundPlayerIndex, int squareIndex) override;
};


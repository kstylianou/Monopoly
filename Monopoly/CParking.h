#pragma once
#include "CSquare.h"

class CParking : public CSquare
{
public:
	// Constructor
	CParking(string square_name, int square_code);

	// Destructor
	~CParking();
	
	// // Print square unique message
	void PrintSquareMessage(s_Player players, int roundPlayerIndex, int squareIndex) override;
};


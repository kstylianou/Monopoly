/*
 * Kyriakos Stylianou
 * kstylianou1@uclan.ac.uk
 * G20795768
 *
 */

#pragma once
#include "CSquare.h"

class CGoToJail : public CSquare
{
public:
	// Constructor
	CGoToJail(std::string name, int code);

	// Destructor
	~CGoToJail();

	// Print square unique message
	void PrintSquareMessage(s_Player players, int roundPlayerIndex, int squareIndex) override;

	// Player goes to jail and pays
	void PlayerReword(s_Player players, int roundPlayerIndex, int squareIndex) override;
};


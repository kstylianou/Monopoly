/*
 * Kyriakos Stylianou
 * kstylianou1@uclan.ac.uk
 * G20795768
 *
 */

#pragma once
#include "CSquare.h"


class CBonus : public CSquare
{
public:
	// Constructor
	CBonus(string name, int code);

	// Destructor
	~CBonus();


	// Player get bonus
	void PlayerReword(s_Player players, int roundPlayerIndex, int squareIndex) override;
};


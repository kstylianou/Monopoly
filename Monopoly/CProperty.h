/*
 * Kyriakos Stylianou
 * kstylianou1@uclan.ac.uk
 * G20795768
 *
 */

#pragma once
#include <string>

#include "CSquare.h"

class CProperty : public CSquare
{
public:
	// Constructor
	CProperty(string name, int code, int cost, int rent, int colour);
	
	// Destructor
	~CProperty();

	// Override functions from CSqure
	void PlayerReword(s_Player players, int roundPlayerIndex, int squareIndex) override;

	// Getters
	int GetCost() { return cost; }

private:
	// Private member functions
	bool CheckIfPropertyIsOwned(s_Player players, int squareIndex);
	void PlayerBuysProperty(s_Player players, int roundPlayerIndex, int squareIndex);
	void PlayerPaysRent(s_Player players, int roundPlayerIndex, int squareIndex);

	// Private variables
	string name; // Square name
	int code; // Square code
	int cost; // Property cost
	int rent; // Property rent
	int colour; // Property colour
};


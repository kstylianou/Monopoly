/*
 * Kyriakos Stylianou
 * kstylianou1@uclan.ac.uk
 * G20795768
 *
 */

#pragma once
#include "CPlayer.h"
#include "CSquare.h"
typedef shared_ptr<vector<shared_ptr<CSquare>>> v_Square;
class CBank
{
public:
	// Constructor
	CBank();

	// Destructor
	~CBank();

	// Public member functions
	void CheckPlayer(shared_ptr<CPlayer> player, v_Square squares);
	void PayMortgageProperty(shared_ptr<CPlayer> player, v_Square squares);

private:
	// Private member functions
	int GetMinPropertyCost(shared_ptr<CPlayer> player, v_Square squares, int& index);
	void MortgagePlayerProperty(shared_ptr<CPlayer> player, v_Square squares, int squareIndex);
};


/*
 * Kyriakos Stylianou
 * kstylianou1@uclan.ac.uk
 * G20795768
 *
 */

#pragma once
#include "CSquare.h"

class CStations : public CSquare
{
public:
	// Constructor
	CStations(std::string name, int code, int cost, int ticket);

	// Destructor
	~CStations();

	// Player buys or pays rent
	void PlayerReword(s_Player players, int roundPlayerIndex, int squareIndex) override;


private:
	// Private member functions
	static bool CheckIfPropertyIsOwned(const s_Player& players, int squareIndex);
	void PlayerBuysProperty(s_Player players, int roundPlayerIndex, int squareIndex);
	void PlayerPaysRent(const s_Player& players, int roundPlayerIndex, int squareIndex) const;
	
	// Private variables
	int cost; // Station cost
	int ticket; // Station ticket
};


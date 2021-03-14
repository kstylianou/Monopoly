#pragma once
#include <string>

#include "CSquare.h"

class CProperty : public CSquare
{
public:
	// Constructor
	CProperty(std::string name, int code, int cost, int rent, int colour);

	void PlayerReword(s_Player players, int roundPlayerIndex, int squareIndex) override;
//

private:
	std::string name; // Square name
	int code; // Square code
	int cost; // Property cost
	int rent; // Property rent
	int colour; // Property colour
	bool isOwned;
};


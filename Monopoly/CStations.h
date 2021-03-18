#pragma once
#include "CSquare.h"

class CStations : public CSquare
{
public:
	CStations(std::string name, int code, int cost, int ticket);
	//~CStations();

	void PlayerReword(s_Player players, int roundPlayerIndex, int squareIndex) override;
	int GetCost() override;

private:
	int cost;
	int ticket;
	bool isOwned;
};


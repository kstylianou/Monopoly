#pragma once
#include "CSquare.h"

class CStations : public CSquare
{
public:
	CStations(std::string name, int code, int cost, int ticket);
	//~CStations();

private:
	int cost;
	int ticket;
};


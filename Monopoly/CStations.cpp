#include "CStations.h"

CStations::CStations(std::string name, int code, int cost, int ticket) : CSquare(name, code)
{
	this->cost = cost;
	this->ticket = ticket;
}


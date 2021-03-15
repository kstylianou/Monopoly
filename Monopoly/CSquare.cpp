#include "CSquare.h"

CSquare::CSquare(string name, int code)
{
	this->name = name;
	this->code = code;
}

void CSquare::PlayerLands(s_Player players, int roundPlayerIndex, int squareIndex)
{
	cout << "<" + players->at(roundPlayerIndex)->GetName() + ">" << " lands on " << this->name << endl;

	PlayerReword(players, roundPlayerIndex, squareIndex);

	cout << "<" + players->at(roundPlayerIndex)->GetName() + ">" << " has  " << static_cast<char>(156) << players->at(roundPlayerIndex)->GetMoney() << endl;
}

void CSquare::PlayerReword(s_Player players, int roundPlayerIndex, int squareIndex)
{
	cout << "<" + players->at(roundPlayerIndex)->GetName() + ">" << " pays "<< static_cast<char>(156) << "0" << endl;
}

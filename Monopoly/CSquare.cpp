#include "CSquare.h"

CSquare::CSquare(string name, int code)
{
	this->name = name;
	this->code = code;
}

void CSquare::PlayerLands(s_Player players, int roundPlayerIndex, int squareIndex)
{
	PrintPlayerSquareLands(players->at(roundPlayerIndex)->GetName());

	PrintSquareMessage(players, roundPlayerIndex, squareIndex);
	
	PlayerReword(players, roundPlayerIndex, squareIndex);

	players->at(roundPlayerIndex)->PrintMoney();
}

void CSquare::PlayerReword(s_Player players, int roundPlayerIndex, int squareIndex)
{
	// Do nothing for this type of square
}

void CSquare::PrintSquareMessage(s_Player players, int roundPlayerIndex, int squareIndex)
{
	// Do nothing for this type of square
}

int CSquare::GetCost()
{
	// Do nothing for this type of square
	return 0;
}

void CSquare::PrintPlayerSquareLands(string name)
{
	cout << "<" + name + ">" << " lands on " << this->name << endl;
}

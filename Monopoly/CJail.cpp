#include "CJail.h"

CJail::CJail(std::string name, int code) : CSquare(name, code)
{
}

void CJail::PrintSquareMessage(s_Player players, int roundPlayerIndex, int squareIndex)
{
    cout << "<" + players->at(roundPlayerIndex)->GetName() + ">" << " is just visiting" << endl;
}



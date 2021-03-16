#include "CParking.h"

CParking::CParking(string name, int code) : CSquare(name, code)
{

}

void CParking::PrintSquareMessage(s_Player players, int roundPlayerIndex, int squareIndex)
{
    cout << "<" + players->at(roundPlayerIndex)->GetName() + ">" << " is resting" << endl;
}


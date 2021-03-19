#include "CParking.h"

// Constructor
CParking::CParking(string name, int code) : CSquare(name, code)
{

}

// Destructor
CParking::~CParking()
{
}

// Print square unique message
void CParking::PrintSquareMessage(s_Player players, int roundPlayerIndex, int squareIndex)
{
    cout << "<" + players->at(roundPlayerIndex)->GetName() + ">" << " is resting" << endl;
}


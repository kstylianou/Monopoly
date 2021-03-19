#include "CJail.h"

// Constructor
CJail::CJail(std::string name, int code) : CSquare(name, code)
{
}

// Destructor
CJail::~CJail()
{
}

// Print square unique message
void CJail::PrintSquareMessage(s_Player players, int roundPlayerIndex, int squareIndex)
{
    cout << "<" + players->at(roundPlayerIndex)->GetName() + ">" << " is just visiting" << endl;
}



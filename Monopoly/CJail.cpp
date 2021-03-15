#include "CJail.h"

CJail::CJail(std::string name, int code) : CSquare(name, code)
{
}

void CJail::PlayerLands(s_Player players, int roundPlayerIndex, int squareIndex)
{
    cout << "<" + players->at(roundPlayerIndex)->GetName() + ">" << " lands on " << this->GetName() << endl;
    cout << "<" + players->at(roundPlayerIndex)->GetName() + ">" << " is just visiting" << endl;

    this->PlayerReword(players, roundPlayerIndex, squareIndex);

    cout << "<" + players->at(roundPlayerIndex)->GetName() + ">" << " has " << static_cast<char>(156) << players->at(roundPlayerIndex)->GetMoney() << endl;
}


#include "CParking.h"

CParking::CParking(string name, int code) : CSquare(name, code)
{

}

void CParking::PlayerLands(s_Player players, int roundPlayerIndex, int squareIndex)
{
    cout << "<" + players->at(roundPlayerIndex)->GetName() + ">" << " lands on " << this->name << endl;
    cout << "<" + players->at(roundPlayerIndex)->GetName() + ">" << " is resting" << endl;

    this->PlayerReword(players, roundPlayerIndex, squareIndex);

    cout << "<" + players->at(roundPlayerIndex)->GetName() + ">" << " has  " << static_cast<char>(156) << players->at(roundPlayerIndex)->GetMoney() << endl;
}


#include "CGoToJail.h"

CGoToJail::CGoToJail(std::string name, int code) : CSquare(name, code)
{
}

void CGoToJail::PlayerLands(s_Player players, int roundPlayerIndex, int squareIndex)
{
    cout << "<" + players->at(roundPlayerIndex)->GetName() + ">" << " lands on " << this->name << endl;
    cout << "<" + players->at(roundPlayerIndex)->GetName() + ">" << " goes to Jail" << endl;
    players->at(roundPlayerIndex)->SetPosition(7);

    this->PlayerReword(players, roundPlayerIndex, squareIndex);

    cout << "<" + players->at(roundPlayerIndex)->GetName() + ">" << " has " << static_cast<char>(156) << players->at(roundPlayerIndex)->GetMoney() << endl;
}

void CGoToJail::PlayerReword(s_Player players, int roundPlayerIndex, int squareIndex)
{
    players->at(roundPlayerIndex)->SetMoney(players->at(roundPlayerIndex)->GetMoney() - 50);

    cout << "<" + players->at(roundPlayerIndex)->GetName() + ">" << " pays " << static_cast<char>(156) << "50" << endl;
}


#include "CGoToJail.h"

CGoToJail::CGoToJail(std::string name, int code) : CSquare(name, code)
{
}

void CGoToJail::PrintSquareMessage(s_Player players, int roundPlayerIndex, int squareIndex)
{
    cout << "<" + players->at(roundPlayerIndex)->GetName() + ">" << " goes to Jail" << endl;
   
}

void CGoToJail::PlayerReword(s_Player players, int roundPlayerIndex, int squareIndex)
{
    players->at(roundPlayerIndex)->SetPosition(7);
	
    players->at(roundPlayerIndex)->SetMoney(players->at(roundPlayerIndex)->GetMoney() - 50);

    cout << "<" + players->at(roundPlayerIndex)->GetName() + ">" << " pays " << static_cast<char>(156) << "50" << endl;
}


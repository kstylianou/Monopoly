#pragma once
#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include "CPlayer.h"

using namespace std;

typedef vector<std::shared_ptr<CPlayer>>* s_Player;
class CSquare
{
public:
	CSquare() {};
	CSquare(string name, int code);
	//~CSquare();

	void PlayerLands(s_Player players, int roundPlayerIndex, int squareIndex);
	virtual void PlayerReword(s_Player players, int roundPlayerIndex, int squareIndex);
	virtual void PrintSquareMessage(s_Player players, int roundPlayerIndex, int squareIndex);
	
	// Getters:
	string GetName() { return name; }
	int GetCode() { return code; }
	virtual int GetCost();

private:
	void PrintPlayerSquareLands(string name);
	
	string name;
	int code;
};


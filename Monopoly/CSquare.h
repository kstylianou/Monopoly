#pragma once
#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include "CPlayer.h"

using namespace std;

typedef shared_ptr<vector<shared_ptr<CPlayer>>> s_Player;

class CSquare
{
public:
	// Empty constructor
	CSquare() {};

	// Constructor
	CSquare(string name, int code);

	// Destructor
	virtual ~CSquare();

	// Public Member functions
	void PlayerLands(s_Player players, int roundPlayerIndex, int squareIndex);

	// Polymorphic functions (virtual)
	virtual void PlayerReword(s_Player players, int roundPlayerIndex, int squareIndex);
	virtual void PrintSquareMessage(s_Player players, int roundPlayerIndex, int squareIndex);
	
	// Getters:
	string GetName() { return name; }
	int GetCode() { return code; }
	virtual int GetCost();

private:

	// Private Member functions
	void PrintPlayerSquareLands(string name);

	// Private variables
	string name; // Square name
	int code; // Square code
};


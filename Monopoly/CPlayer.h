/*
 * Kyriakos Stylianou
 * kstylianou1@uclan.ac.uk
 * G20795768
 *
 */

#pragma once
#include <memory>
#include <string>
#include <vector>

#define SQUARES_NUM		26
#define RED_COLOUR		2
#define GREY_COLOUR		2
#define BROWN_COLOUR	2
#define ORANGE_COLOUR	3
#define YELLOW_COLOUR	2
#define GREEN_COLOUR	2
#define BLUE_COLOUR		3
#define PURPLE_COLOUR	2

#define PLAYER_PLAYING	1
#define PLAYER_BANKRUPT	0

using namespace std;

typedef unique_ptr<vector<int>> v_int;
typedef vector<int> v_newInt;

class CPlayer
{
public:
	// Constructor
	CPlayer(string name);

	// Destructor
	~CPlayer();

	// Member functions
	int roll();
	int MovePlayerPosition(int roolNum);
	void PlayerPassesGo();
	void PlayerOwnsNewProperty(int propertyIndex, int colour);
	bool PlayerOwns(int propertyIndex);
	bool PlayerOwnsAllColour(int colour);
	void PrintMoney();
	void PlayerBankrupt();

	// Getters
	string GetName() const { return name; }
	int GetMoney() const { return money; }
	void SetMoney(int i) { money = i; }
	void SetPosition(int i) { position = i; }
	int OwnPropertyLength() const { return playerOwns->size(); }
	bool isPlaying() const { return this->state; }
	int GetMortgageLength() const { return mortgageProperties->size(); }
	bool CheckIfPlayerOwnsProperty(int index) const { return (count(playerOwns->begin(), playerOwns->end(), index)); }
	bool CheckIfPropertyIsMortgage(int index) const { return (count(mortgageProperties->begin(), mortgageProperties->end(), playerOwns->at(index))); }
	bool CheckIfPropertyIsMortgageBySquare(int index) const { return (count(mortgageProperties->begin(), mortgageProperties->end(), index)); }
	bool PlayerHasMortgageProperty() const { return (!mortgageProperties->empty()); }
	int GetMortgageByIndex(int index) const { return mortgageProperties->at(index); }
	bool PlayerHasNegativeMoney() const { return (this->money < 0); }
	int GetOwnPropertyByIndex(int index) const { return playerOwns->at(index); }
	bool GetPlayerOwnsStation(int index) const { return (count(playerStationOwns->begin(), playerStationOwns->end(), index)); }

	// Setters
	void SetPlayerMortgage(int squareIndex) const { mortgageProperties->push_back(squareIndex); }
	void PlayerPaysMortgageProperty(int squareIndex) const { mortgageProperties->erase(remove(mortgageProperties->begin(), mortgageProperties->end(), squareIndex), mortgageProperties->end()); }
	void PlayerOwnsStation(int index) { playerStationOwns->push_back(index); }

private:
	string name;
	int position;
	int money;
	v_int playerOwns;
	v_int colourSquares;
	v_int mortgageProperties;
	v_int playerStationOwns;
	int state;
};







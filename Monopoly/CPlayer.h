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
	CPlayer(string name);
	~CPlayer();
	int roll();
	int MovePlayerPosition(int roolNum);
	void PlayerPassesGo();
	void PlayerOwnsNewProperty(int propertyIndex, int colour);
	bool PlayerOwns(int propertyIndex);
	bool PlayerOwnsAllColour(int colour);
	void PrintMoney();
	void PlayerMortgage(int squareIndex);
	bool CheckIfPlayerOwnsProperty(int index);
	bool CheckIfPropertyIsMortgage(int index);
	bool CheckIfPropertyIsMortgageBySquare(int index);
	bool PlayerHasMortgageProperty();
	void PlayerPaysMortagePropery(int squareIndex);
	int GetMortgageByIndex(int index);
	bool PlayerHasNegativeMoney();
	int GetOwnPropertyByIndex(int index);
	void PlayerBankrupt();
	
	string GetName() const { return name; }
	int GetMoney() const { return money; }
	void SetMoney(int i) { money = i; }
	void SetPosition(int i) { position = i; }
	int OwnPropertyLength() { return playerOwns->size(); }
	bool isPlaying() { return this->state; }
	int GetMortgageLength() { return mortgageProperties->size(); }

private:
	string name;
	int position;
	int money;
	v_int playerOwns;
	v_int colourSquares;
	v_int mortgageProperties;
	int state;
};







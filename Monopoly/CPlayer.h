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


using namespace std;

typedef vector<int> v_PlayerOwns;

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
	
	string GetName() { return name; }
	int GetMoney() { return money; }
	void SetMoney(int i) { money = i; }
	void SetPosition(int i) { position = i; }
private:
	string name;
	int position;
	int money;
	v_PlayerOwns* playerOwns;
	v_PlayerOwns* colourSquares;
};




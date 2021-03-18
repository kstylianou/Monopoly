#pragma once
#include <memory>
#include <memory>
#include <string>
#include <vector>



#include "CBank.h"
#include "CPlayer.h"
#include "CBonus.h"
#include "CGo.h"
#include "CGoToJail.h"
#include "CJail.h"
#include "CParking.h"
#include "CPenalty.h"
#include "CProperty.h"
#include "CStations.h"

typedef shared_ptr<vector<shared_ptr<CPlayer>>> v_Player;
typedef vector<shared_ptr<CPlayer>> v_newPlayer;


typedef shared_ptr<vector<shared_ptr<CSquare>>> v_Square;
typedef vector<shared_ptr<CSquare>> v_new_Square;

typedef vector<shared_ptr<string>> v_PlayerNames;
typedef shared_ptr<CSquare> s_Squares;

typedef unique_ptr<CBank> u_Bank;

#define STATE_RUNNING   1
#define STATE_FINISH    0
#define PLAYERS_NUM		4
#define SQUARES_NUM		26

class CManager
{
public:
	// Constructor
	CManager();

	// Destructor
	~CManager();

	// Methods
	bool SetGame();
	void StartGame();
	void UpdateRound();
	void UpdateGame();

protected:
	// Member methods
	s_Squares SetSquares(string line);
	bool SetPlayers();
	bool OpenSquareFile();
	static void WelcomeMessage();
	void GetFirstPlayer();
	void GetWinner();
	void PlayerAreBankrupt();


	v_Player player;
	v_Player sortedPlayers;
	v_Square square;
	v_PlayerNames player_names;
	u_Bank bank;
	int seed;
	int round;
	int state;
	int playerSort[PLAYERS_NUM];
};


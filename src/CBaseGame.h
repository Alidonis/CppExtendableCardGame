#pragma once

//--------------------
// CBaseGame
// A base for creating games
//-------------------

class CPlayer;
class CEngine;

class CBaseGame
{
public:
	CBaseGame();
	~CBaseGame() = default;
	void addPlayer(int id);
	std::vector<std::unique_ptr<CPlayer>>& getPlayers();
private:
	std::vector <std::unique_ptr<CPlayer>> players;
	std::unique_ptr<CEngine> ParentEngine;
};

/*
	This class allows for creation of games (or gamemodes, rather)

	this class will handle everything about how the game is played

	This class will be instantiable as a demo game

	Players will be able to 1V1 using their cards via card duels
	
	Each card will have a power level, and a cost.
	
	Higher power level wins the fight. if power is equal, do nothing

	the goal is to have beaten 10 cards first
*/
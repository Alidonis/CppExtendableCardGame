#pragma once

//--------------------
// CBaseGame
// A base for creating games
//-------------------

class CPlayer;

struct CBaseGameHostInfo 
{
	std::string serverName;
	std::string hostName;
	bool isPublic;
	std::string password;
};

inline void hi()
{
	std::cout << "Function pointer called function 'Hi'\n";
}

class CBaseGame
{
public:
	CBaseGame(); 
	~CBaseGame() = default;
	void addPlayer(int id);
	void callPointer() { this->fcnPtr(); };
private:
	std::vector <std::unique_ptr<CPlayer>> players;
	std::function<void()> fcnPtr{ &hi };
};

/*
	This class allows for creation of games (or gamemodes, rather)
	Gonna go with a goldsource sdk style inheritance system

	this class will handle everything about how the game is played

	This class will be instantiable as a demo game

	Players will be able to 1V1 using their cards via card duels
	
	Each card will have a power level, and a cost.
	
	Higher power level wins the fight. if power is equal, do nothing

	the goal is to have beaten 10 cards first
*/
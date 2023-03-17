#include "CommonHeaders.h"

CBaseGame::CBaseGame()
{
	addPlayer(0);
}

void CBaseGame::addPlayer(int id)
{
	if (id < 0) { return; }
	for (int i = 0; i < players.size(); i++)
	{
		if (players[i]->getId() == id)
		{
			return;
		}
	}
	players.push_back(std::make_unique<CPlayer>(id));
}

std::vector<std::unique_ptr<CPlayer>>& CBaseGame::getPlayers()
{ 
	return players;
}

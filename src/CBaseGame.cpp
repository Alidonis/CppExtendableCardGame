#include "CommonHeaders.h"

CBaseGame::CBaseGame()
{
	std::cout << "Init CBaseGame\n";
}

void CBaseGame::addPlayer(int id)
{ //TODO : validate id
	bool isValidId = true; //gonna make it in a copy to observe the changes
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
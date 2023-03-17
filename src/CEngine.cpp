#include "CommonHeaders.h"

CEngine::CEngine()
{
	int err = this->clientLoop(0);
	if (err > 0) { std::cout << "Oops! some error happened too many times !\n"; }
}

int CEngine::clientLoop(int _retryAttempt) {
	int retryAttempt = _retryAttempt;
	if (retryAttempt > 3) { return 1; }
	std::cout << "Waiting for input\n0. exit\n1. create match\n2. Settings\n";
	std::string input;
	std::cin >> input;
	int choice;
	try 
	{
		choice = std::stoi(input);
	}
	catch (std::exception error) 
	{
		std::cout << "You did not type in a valid query. Or my code as gone wrong.\n";
		CEngine::clientLoop(retryAttempt + 1);
		return 1;
	}

	switch (choice)
	{
	case 0:
		return 0;
		break;
	case 1:
		this->createMatch(nullptr);
		break;
	case 2:
		std::cout << "No settings exist for now.\n";
		break;
	default:
		std::cout << "That's not a valid option.\n";
		CEngine::clientLoop(retryAttempt);
		break;
	}
	return 0;
}

void CEngine::createMatch(CBaseGame* gameType)
{
	std::cout << "type addPlayer to add a new player\type start to start the game\n";
	std::cout << " --- Game Lobby ---\nPlayer 0 [Host]\n";
	if (gameType != nullptr)
	{
		gameInstance.reset(gameType);
	}
	else
	{
		gameInstance.reset(new CBaseGame());
	}
	
	bool isLobbyReady = false;
	int nextPlrId = 1;
	while (!isLobbyReady)
	{
		std::string x;
		std::cin >> x;
		if (x == "addPlayer")
		{
			this->gameInstance->addPlayer(nextPlrId);
			nextPlrId++;
		}
		if (x == "listPlayers") { calculatePlayers(this->gameInstance->getPlayers()); }
		if (x == "start") { isLobbyReady = true; }
	} //Well really it's us all
}

std::string calculatePlayers(std::vector<std::unique_ptr<CPlayer>>& players)
{
	for ( int i = 0 ; i < players.size() ; i++ )
	{
		std::cout << players[i]->getId() << "\n";
	} 
}
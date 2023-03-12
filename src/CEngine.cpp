#include "CommonHeaders.h"

CEngine::CEngine()
{
	this->clientLoop();
}

void CEngine::clientLoop() {
	std::cout << "Client loop fired.\n";
}

void CEngine::createMatch(CBaseGame* gameType)
{
	if (gameType != nullptr)
	{
		gameInstance.reset(gameType);
	}
	else
	{
		gameInstance.reset(new CBaseGame());
	}
}
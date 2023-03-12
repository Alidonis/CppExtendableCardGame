#include "CommonHeaders.h"

CEngine::CEngine()
{
	this->clientLoop();
}

void clientLoop() {

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
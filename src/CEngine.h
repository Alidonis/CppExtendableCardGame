#pragma once

class CBaseGame;
class CPlayer;

class CEngine
{
public:
	CEngine();
	~CEngine() = default;
	void createMatch(CBaseGame* gameType);
private:
	int clientLoop(int retryAttempt);
	std::unique_ptr<CBaseGame> gameInstance = nullptr;
};


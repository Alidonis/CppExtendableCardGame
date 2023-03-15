#pragma once

class CBaseGame;
class CPlayer;

template<class T>
class CEngine
{
public:
	CEngine();
	~CEngine() = default;
	void createMatch(CBaseGame* gameType);
private:
	T e;
	int clientLoop(int retryAttempt);
	std::unique_ptr<CBaseGame> gameInstance = nullptr;
};


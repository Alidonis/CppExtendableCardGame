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
	void clientLoop();
	std::unique_ptr<CBaseGame> gameInstance = nullptr;
};


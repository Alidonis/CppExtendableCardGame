#pragma once

class CBaseGame;
class CPlayer;

class CEngine
{
public:
	CEngine();
	~CEngine() = default;
	void clientLoop();
	void createMatch(CBaseGame* gameType);
private:
	std::unique_ptr<CBaseGame> gameInstance = nullptr;
};


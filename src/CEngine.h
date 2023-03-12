#pragma once

class CBaseGame;
class CPlayer;

class CEngine
{
public:
	CEngine();
	~CEngine() = default;
	void clientLoop() { std::cout << "Client lopp fired.\n"; };
	void createMatch(CBaseGame* gameType);
private:
	std::unique_ptr<CBaseGame> gameInstance = nullptr;
};


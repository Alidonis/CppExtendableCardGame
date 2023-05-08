#pragma once

class CBaseCard;

class CPlayer
{
public:
	CPlayer(int id);
	~CPlayer() = default;
	inline int getId() { return id; };
	std::vector<std::unique_ptr<CBaseCard>>& getHand() { return this->hand; };
	void addCard(std::unique_ptr<CBaseCard>&& Card);
private:
	std::vector<std::unique_ptr<CBaseCard>> hand;
	int id;
};
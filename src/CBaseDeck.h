#pragma once

class CDeck
{
public:
	CDeck();
	~CDeck() = default;
	std::vector<std::unique_ptr<CBaseCard>>& getCards();
	void setCardsPool(std::vector<std::unique_ptr<CBaseCard>>&);
	void Draw(CPlayer plr, int amount = 1);
	void shuffle();
	std::vector<std::string> scry(int amount = 1);
private:
	std::vector<std::unique_ptr<CBaseCard>> cardspool;
};
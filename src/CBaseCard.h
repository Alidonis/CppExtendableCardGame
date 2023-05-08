#pragma once

class CBaseCard
{
public:
	CBaseCard();
	~CBaseCard() = default;
	const std::string name = "Base card, Devs love it";
	void remove() { std::cout << "method not implemented\n"; };
protected:
	virtual void event_onCardCreated() { std::cout << "Instance of CBaseCard initiated"; };
	virtual void event_onCardPlayed() { std::cout << "CBaseCard : Card played";  };
	virtual void event_onAllTurns(std::string phase) { std::cout << "CBaseCard : turn event received";  };
	virtual void event_onFriendlyTurns(std::string phase) { std::cout << "CBaseCard : friendly turn event received";  };
	virtual void event_onEnemiesTurns(std::string phase) { std::cout << "CBaseCard : enemy turn event received";  };
private:
};
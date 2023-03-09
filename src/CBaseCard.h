#pragma once

class CBaseCard
{
public:
	CBaseCard();
	void remove();
protected:
	virtual void event_onCardCreated() { std::cout << "Instance of CBaseCard initiated"; };
	virtual void event_onCardPlayed() { std::cout << "CBaseCard : Card played";  };
	virtual void event_onAllTurns() { std::cout << "CBaseCard : turn event received";  };
	virtual void event_onFriendlyTurns() { std::cout << "CBaseCard : friendly turn event received";  };
	virtual void event_onEnemiesTurns() { std::cout << "CBaseCard : enemy turn event received";  };
private:
	std::string name = "Default Name";
};
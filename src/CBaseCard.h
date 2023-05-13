#pragma once

class CBaseCard
{
public:
	CBaseCard();
	~CBaseCard() = default;
	virtual std::string getName() { return "Base card, Devs love it"; }
	void remove() { std::cout << "method not implemented\n"; };
	virtual void event_onCardCreated() { std::cout << "Instance of CBaseCard '" << getName() << "' initiated" << std::endl; }
	virtual void event_onTurnPhase(std::string phase) { std::cout << "Phase " << phase << " event triggered" << std::endl; }
private:
};
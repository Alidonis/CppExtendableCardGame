#pragma once

class CBaseCard
{
public:
	CBaseCard();
	~CBaseCard() = default;
	virtual std::string getName() { return "Base card, Devs love it"; }
	void remove() { std::cout << "method not implemented\n"; };
	virtual void event_onTurnPhase(const char* phase) { std::cout << "Phase " << phase << " event triggered" << std::endl; }
private:
};
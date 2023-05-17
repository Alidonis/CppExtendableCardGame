#pragma once

class CBaseCard
{
public:
	CBaseCard();
	~CBaseCard() = default;
	virtual std::string getName() { return "CBaseCard"; }
	void remove() { std::cout << "method not implemented\n"; };
	virtual void event_onTurnPhase(const char* phase);
private:
};
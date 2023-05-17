#pragma once
class TestCard : public CBaseCard
{
public:
	TestCard();
	~TestCard() = default;
	std::string getName() override { return "Test Card"; }
	void event_onTurnPhase(const char* phase) override;
};
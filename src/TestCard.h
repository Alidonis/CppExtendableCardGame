#pragma once
class TestCard : CBaseCard
{
public:
	TestCard();
	~TestCard() = default;
	std::string getName() override { return "God's Test Card"; }
	virtual void event_onCardCreated() override { std::cout << "Instance of TestCard initiated" << std::endl; }
};

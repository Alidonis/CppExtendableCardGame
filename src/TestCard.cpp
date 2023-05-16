#include "CommonHeaders.h"
#include "CommonClassHeaders.h"

#include "cardlinker.h"

#include "TestCard.h"

void TestCard::event_onTurnPhase(const char* phase)
{
	if (phase == "inst_test") {
		std::cout << "TestCard : received event inst_test";
	}
}

M_LINK_CARD("Test Card", TestCard);

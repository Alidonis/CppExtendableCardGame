#include "CommonHeaders.h"
#include "CommonClassHeaders.h"

CBaseCard::CBaseCard()
{
}

void CBaseCard::event_onTurnPhase(const char* phase)
{
	if (phase == "inst_test") {
		std::cout << "CBaseCard : received event inst_test";
	}
}
#include "CommonHeaders.h"
#include "CommonClassHeaders.h"
#include "cardlinker.h"

CBaseCard::CBaseCard()
{
}

void CBaseCard::event_onTurnPhase(const char* phase)
{
	if (phase == "inst_test") {
		std::cout << "CBaseCard : received event inst_test";
	}
}

M_LINK_CARD("Base Card", CBaseCard);
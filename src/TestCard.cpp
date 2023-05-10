#include "CommonHeaders.h"
#include "CommonClassHeaders.h"

#include "cardlinker.h"

#include "TestCard.h"

TestCard::TestCard()
{
	this->event_onCardCreated();
}

M_LINK_CARD("Test Card", TestCard);

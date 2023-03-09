#include <cassert>
#include <iostream>
#include <string>

#include "CBaseCard.h"

CBaseCard::CBaseCard()
{
	this->event_onCardCreated();
}
#include <iostream>
#include <string>
#include <functional>
#include <memory>

#include "CBaseCard.h"

CBaseCard::CBaseCard()
{
	this->event_onCardCreated();
}
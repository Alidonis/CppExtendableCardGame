#include <iostream>
#include <string>
#include <functional>
#include <memory>

#include "CPlayer.h"
#include "CBaseCard.h"

CPlayer::CPlayer(int id)
{
	this->id = id;
}

int CPlayer::getId()
{
	return this->id;
}
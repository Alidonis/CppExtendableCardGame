#include <memory>
#include <vector>

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
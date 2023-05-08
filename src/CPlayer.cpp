#include "CommonHeaders.h"
#include "CommonClassHeaders.h"

CPlayer::CPlayer(int id)
{
	this->id = id;
}

void CPlayer::addCard(std::unique_ptr<CBaseCard>&& Card)
{
	hand.push_back(std::move(Card));
}

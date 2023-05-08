#include "CommonHeaders.h"
#include "CommonClassHeaders.h"

CDeck::CDeck()
{

}

std::vector<std::unique_ptr<CBaseCard>>& CDeck::getCards()
{ 
	return cardspool;
}

void CDeck::Draw(CPlayer plr, int amount)
{
	for (size_t i = 0; i < amount; i++)
	{
		plr.addCard(std::move(cardspool[0]));
	}
}

/*std::vector<std::string> CDeck::scry(int amount)
{
	std::vector<std::string> out;
	for (size_t i = 0; i < amount; i++)
	{
		out.push_back(cardspool[i]);
	}
	return out;
}*/

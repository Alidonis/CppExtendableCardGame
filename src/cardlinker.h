#pragma once
#include "CommonHeaders.h"
#include "CBaseCard.h"
using EntityFactory = CBaseCard*();

struct cardFactoryPair;
inline std::vector<cardFactoryPair*> CardLinker_Pairs;

struct cardFactoryPair
{
	cardFactoryPair(const char* Classname, EntityFactory* Factory)
		: classname(Classname), factory(Factory)
	{
		CardLinker_Pairs.push_back(this);
	}

	std::string_view classname;
	EntityFactory* factory;
};

#define M_LINK_CARD(cardname, dllclass) \
    cardFactoryPair __Factory##dllclass = cardFactoryPair( cardname, [](){ return new (CBaseCard*)dllclass(); } )
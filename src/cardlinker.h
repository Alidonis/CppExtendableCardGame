#pragma once
#include "CommonHeaders.h"
#include "CBaseCard.h"
using EntityFactory = CBaseCard*();

uint8_t e = 1;

struct cardFactoryPair;
inline std::vector<cardFactoryPair> Pairs;

struct cardFactoryPair
{
	cardFactoryPair(std::string Classname, EntityFactory* Factory)
		: classname(Classname), factory(Factory)
	{
		Pairs.push_back(*this);
	}

	std::string classname;
	EntityFactory* factory;
};

#define M_LINK_CARD(cardname, dllclass) \
EntityFactoryPair cardname = EntityFactoryPair( #cardname, [](){ return new ##dllclass(); } );
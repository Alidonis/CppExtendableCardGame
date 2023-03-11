#include <iostream>
#include <string>
#include <functional>
#include <memory>

#include "CPlayer.h"
#include "CBaseCard.h"
#include "CBaseGame.h"

int main()
{
	CBaseGame *MyGame = new CBaseGame;
	MyGame->callPointer();
}

#include <iostream>
#include <string>
#include <functional>
#include <memory>

#include "CBaseGame.h"

int main()
{
	CBaseGame *MyGame = new CBaseGame;
	MyGame->callPointer();
}
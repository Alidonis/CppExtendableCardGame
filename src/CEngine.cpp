#include "CommonHeaders.h"

CEngine::CEngine()
{
	int err = this->clientLoop(0);
	if (err > 0) { std::cout << "Oops! some error happened too many times !\n"; }
}

int CEngine::clientLoop(int _retryAttempt) {
	int retryAttempt = _retryAttempt;
	if (retryAttempt > 3) { return 1; }
	std::cout << "Waiting for input\n1. create match\n2. Settings\n";
	std::string input;
	std::cin >> input;
	int choice;
	try 
	{
		choice = std::stoi(input);
	}
	catch (std::exception error) 
	{
		std::cout << "You did not type in a valid query. Or my code as gone wrong.\n";
		CEngine::clientLoop(retryAttempt + 1);
		return 1;
	}

	switch (choice)
	{
	case 1:
		std::cout << "Hello ! I was too lazy to implement this function.\n";
		break;
	case 2:
		std::cout << "No settings exist for now.\n";
		break;
	default:
		std::cout << "That's not a valid option.\n";
		CEngine::clientLoop(retryAttempt);
		break;
	}
	return 0;
}

void CEngine::createMatch(CBaseGame* gameType)
{
	if (gameType != nullptr)
	{
		gameInstance.reset(gameType);
	}
	else
	{
		gameInstance.reset(new CBaseGame());
	}
}
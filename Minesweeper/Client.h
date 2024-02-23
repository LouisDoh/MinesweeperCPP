#pragma once
#include "Grid.h"

class Client
{
	private:
		Grid gameBoard;
		static Grid getGameSettings();

	public:
		Client();
		void gameLoop();
		void takeTurn();
};
#include "Client.h"
#include <sstream>
#include <limits>

Client::Client() : gameBoard(Client::getGameSettings()){
}

Grid Client::getGameSettings() {
	std::cout << "How many columns would you like in your board?\n";
	int cols;
	std::cin >> cols;

	std::cout << "How many rows would you like?\n";
	int rows;
	std::cin >> rows;

	std::cout << "And how many mines in that grid? We'd suggest something around " << ((cols * rows) / 10) << " (10% of tiles).\n";
	int mines;
	std::cin >> mines;

	std::cout << "Okay! Setting up the game...\n";

	return Grid(cols, rows, mines);
}

void Client::gameLoop() {
	while (gameBoard.getState() == GameState::ongoing) {
		std::cout << gameBoard << "\n";
		takeTurn();
	}
	
	std::string gameOverMessage = "";
	if (gameBoard.getState() == GameState::won) {
		gameOverMessage = "You won! Congratulations!";
	}
	else {
		gameOverMessage = "Oh no! You clicked a bomb and lost!";
	}

	std::cout << gameOverMessage << "\nWould you like to play again? (y/n)\n";

	std::string response;
	std::cin >> response;
	
	if (response == "y") {
		gameLoop(); //this is limited by the stack... could lift out to outer function and while loop it? gameloop return true for play again, false for not?
	}
} 

void Client::takeTurn() {
	std::string raw = "";
	std::stringstream stream;
	int col;
	int row;
	std::string action;
	std::string nextToken;

	while (true) {
		std::cout << "Please enter a move in the format row,col,action (d = dig, f = flag/unflag):\n";
		std::cin >> raw;
		stream.str(raw);
		try {
			std::getline(stream, nextToken, ',');
			row = stoi(nextToken)-1;

			std::getline(stream, nextToken, ',');
			col = stoi(nextToken)-1;

			std::getline(stream, action);

			if (action == "d" || action == "f") {
				break;
			}
		}
		catch (...) {
			std::cout << "Invalid input!";
		}
	}

	if (action == "d") {
		gameBoard.clickTile(row, col);
	}
	else {
		gameBoard.flagTile(row, col);
	}
}
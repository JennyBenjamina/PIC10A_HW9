#include<iostream>
#include <string>
#include "LineOfMines.h"
#include "Player.h"

int main() {

	// The game is explained
	std::cout <<
		"This is a game of Linesweeper: mines are arranged on a line. \n"
		"You select a position to reveal what is there. \n"
		"For every safe location you reveal, you get +1 point. \n"
		"If you reveal a mine, you get a score of 0. \n"
		"A given location may have a mine to either its left, right, both, or neither. \n"
		"The number of neighbouring mines of a revealed location 0/1/2 is displayed. \n"
		"You can continue playing until you either hit a mine or choose not to reveal any more locations." << '\n';

	/* the rest is for you to fill in */
	std::cout << "What is your name? "; //get user name
	std::string name; //user name
	getline(std::cin, name); //store user name
	Player user(name); //instantiate Player class and declare name

	std::cout << "How long do you want the line? ";
	int length_line; //length of linesweeper
	std::cin >> length_line; //user inputs length of linesweeper

	std::cout << "How many mines do you want on the line? ";
	int num_mines; //number of mines
	std::cin >> num_mines; //user determines number of mines



	char again = 'y';
	while (again == 'y') {
		LineOfMines game(length_line, num_mines); //instantiate LineOfMines class with the user length of line and number of mines
		game.displayMine();
		std::cout << '\n';

		char reveal = 'y'; //y or n based on user answer
		while (!game.hasHitMine() && reveal != 'n') { //keep looping while the user has not hit a mine and if the user wants to keep playing
			std::cout << "What position location would you like to reveal? ";
			int pos; //position
			std::cin >> pos; //user's guess of position
			game.makeSelection(pos); //check if position has a mine

			if (!game.hasHitMine()) { //if user did not hit a bomb, ask user to go again
				std::cout << "Would you like to make another location? [y/n] ";
				std::cin >> reveal;
				if (reveal == 'n') { //user inputs n, reveal the mines
					std::cout << "The mine positions are now revealed: " << '\n';
					game.grandReveal(); //reveal all the mine locations
					int current_score = game.getScore();//store current game score

					if (user.check_record(current_score)) {//check if this score is better than user's best score
						std::cout << "You have a new high score of " << user.get_max_score() << '!' << '\n';
					}
					else {
						std::cout << "You scored " << current_score << " but your best score is still " << user.get_max_score() << "." << '\n';
					}
				}
			}
			else {
				std::cout << "You scored " << game.getScore() << " but your best score is still " << user.get_max_score() << "." << '\n';
			}

		}
		std::cout << "Would you like to play again? [y/n] "; //loop through again if user chooses y.
		std::cin >> again;
	}
	
	std::cout << user.get_name() << ", your top score was " << user.get_max_score() << ".";

	return 0;
}
#include "Player.h"

/* Definition of Player constructor and member functions */

//Player constructor that sets the name of player and default score to 0.
Player::Player(const std::string & _name) : name(_name), bestScore(0) {};

//this function returns the name of the player
const std::string& Player::get_name() const {
	return name;
}

//this function returns the max score
int Player::get_max_score() const {
	return bestScore;
}

//this function checks to see if inputted score is better than bestScore.
bool Player::check_record(int score) {
	if (score > bestScore) { //if the inputted score is better than the stored bestScore
		bestScore = score; //update bestScore
		return true;
	}
	return false;
}


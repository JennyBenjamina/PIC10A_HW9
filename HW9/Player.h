#ifndef _PLAYER_
#define _PLAYER_
#include <string>

/**
* @class Player represents the player that is playing linesweeper
*/
class Player {
public: 
	/**
	* Constructor: this takes a string of the player's name to create the Player object. Default bestScore is set to 0.
	* @param name this is the name of the player.
	*/
	Player(const std::string& name);

	/**
	* This function returns the string representation of the member variable name
	* @return return the name of the player
	*/
	const std::string& get_name() const;

	/**
	* This function returns the max score 
	* @return the max score
	*/
	int get_max_score() const;

	/**
	* This function checks to see if this current score is better than the stored bestScore
	* @param score current score to check is better than bestScore
	* @return true if the new score is better than the bestScore and false if it is not
	*/
	bool check_record(int score);

private:
	std::string name;
	int bestScore;
};

#endif
#ifndef _LINEOFMINES_
#define _LINEOFMINES_

#include <string>
#include <vector>

/**
* @class LineOfMines represents the characteristics of the line
*/
class LineOfMines {
public:
	/**
	* Constructor: takes two inputs for the number of locations and the number of mines
	*
	* @param lineLength this determines the length of the locations
	* @param numberOfMines this determines the number of mines in the location
	*/
	LineOfMines(size_t lineLength, size_t numberOfMines);

	/**
	* this function modifies each locationDisplays value to “ * ” if there is a mine there, 
	* and subsequently calls display.
	*/
	void grandReveal();

	/**
	* this function accepts an int of the player's desired location to be revealed. It updates the corresponding
	* locationDisplays value to __*__ if mine is present. Otherwise, sets the locationDisplays to __1__,
	* __0__, __2__, depending on how many adjacent mines there are.
	* @param position this is the position to reveal
	*/
	void makeSelection(int position);

	/**
	* this function returns whether or not a mine has been hit; true if yes, false if not.
	* @return true if mine has been hit, false if mine has not been hit
	*/
	bool hasHitMine();

	/**
	* this function returns the player’s score: 0 if they have hit a mine and otherwise the
	* number of safe locations they have revealed
	* @return 0 if the player hit a mine
	*/
	int getScore();

private:
	size_t lineLength, numberOfMines;
	int score;
	std::vector<std::string> locationDisplays;
	std::vector<int> neighboringMineCounts, mineLocations;
	bool hitMine;

	/**
	* this function places mines on the line
	*/
	void placeMines();

	/**
	* this function sets the values of neighboringMineCounts
	*/
	void setCounts();

	/**
	* this function returns true if there is a mine at the inputted position and otherwise false
	*
	* @param pos_num the position to inspect whether there is a mine.
	* @return true if there is a mine there, otherwise false.
	*/
	bool containsMine(int pos_num);

	/**
	* this function displays the board
	*/
	void display();


};

#endif
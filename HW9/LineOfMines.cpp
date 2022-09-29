#include "LineOfMines.h"
#include <iostream>
#include <iomanip>
#include <set>
#include <ctime>
#include <cstdlib>
/* Definition of LineOfMines constructor and its member functions */

//LineOfMines constructor sets the number of location and number of mines in the locations
LineOfMines::LineOfMines(size_t _lineLength, size_t _numberOfMines) : lineLength(_lineLength), 
numberOfMines(_numberOfMines), score(0), locationDisplays(lineLength, "_____"), 
neighboringMineCounts(_lineLength, 0),
hitMine(false), mineLocations(numberOfMines, 0) {
	display();
	placeMines();
	setCounts();
};
	


//this function places mines in mineLocations distinctly
void LineOfMines::placeMines() {
	srand(time(nullptr));//seed the random generator

		std::set<int> sorter; //declare a set to get distinct numbers
		std::set<int>::iterator itr; //set iterator 
		while (sorter.size() != numberOfMines) { //loop until sorter is of the same size as number of mines
			int ran = rand() % lineLength + 1; //random number generator
			sorter.insert(ran); //insert random number in set
		}

		int i = 0; //counter
		for (itr = sorter.begin(); itr != sorter.end(); ++itr) { //loop through set
			mineLocations[i] = *itr; //store in mineLocations vector
			++i; //increment counter
		}


}

//this function sets the values of neighboringMineCounts appropriately
void LineOfMines::setCounts() {
		for (size_t j = 0; j < mineLocations.size(); ++j) //loop through mine locations
		{
			neighboringMineCounts[mineLocations[j] - 1] = -1; //assign -1 as the mine
		} 

		for (size_t i = 0; i < neighboringMineCounts.size(); ++i) {

			if (neighboringMineCounts[i] != -1) {//if i is not a mine
				if ((i != 0) && (i != neighboringMineCounts.size() - 1)) {//if i is not on a edge
					if ((neighboringMineCounts[i + 1] == -1) && (neighboringMineCounts[i - 1] == -1)) { //check to see if there are two mines surrounding this block
						neighboringMineCounts[i] = 2;
					}
					else if ((neighboringMineCounts[i + 1] == -1) || (neighboringMineCounts[i - 1] == -1)) {//check to see if there is one mine
						neighboringMineCounts[i] = 1;
					}
				}
				else if (i == 0) {//this is for the first block
					if (neighboringMineCounts[i + 1] == -1) { //if the block adjacent to the first block is a mine
						neighboringMineCounts[i] = 1;
					}
				}
				else if (i == neighboringMineCounts.size() - 1) {//this is for the last block
					if (neighboringMineCounts[i - 1] == -1) {//if the block adjacent to the last block is a mine
						neighboringMineCounts[i] = 1;
					}
				}
			}
		}
		}

//this function returns true if the position contains a mine
bool LineOfMines::containsMine(int pos_num) {
	for (size_t i = 0; i < mineLocations.size(); ++i) {//loop through mineLocations
		if (pos_num == mineLocations[i]) { //check if the inputted position is a mineLocation
			return true;
		}
	}
	return false;
}

//this function displays the linesweeper board
void LineOfMines::display() {
	for (size_t i = 1; i <= lineLength; ++i) {
		std::cout << std::setw(6) << std::left << i; //set the locationDisplay left justified
	}

	std::cout << '\n'; //skip line
	for (size_t i = 0; i < locationDisplays.size(); ++i)
	{
		std::cout << locationDisplays[i] << ' '; //display the locations
	}
	std::cout << '\n';//skip line
}

//this function reveals the mines
void LineOfMines::grandReveal() {
	for (size_t i = 0; i < mineLocations.size(); ++i)
	{
		locationDisplays[mineLocations[i] - 1] = "__*__"; //change the mine location strings to mine image
	}
	display(); //display the mines
}

//this function returns true if a mine has been hit and false if not
bool LineOfMines::hasHitMine() {
	if (hitMine) { //check if mine has been hit
		return true;
	}
	return false;
}

int LineOfMines::getScore() {
	if (hitMine) { //if mine has been hit, score is 0
		return 0;
	}
	else {
		for (size_t i = 0; i < locationDisplays.size(); ++i) { //it seems to double, not accumulate!
			if ((locationDisplays[i] != "_____") && (locationDisplays[i] != "__*__")) {//incremenet score if locationDisplay meets these parameters
				++score;//increment score
			}
		}
	}
	return score;
}

void LineOfMines::makeSelection(int position) {
	bool mine = containsMine(position);//check if mine has been hit
	if (mine == true) {//check if mine is true
		hitMine = true;
		grandReveal();//reveal where all the bombs are
	}
	else {
		char neighboringMine = neighboringMineCounts[position - 1] + '0'; //change integer to character
		std::string s(1,neighboringMine);//change character to string
		locationDisplays[position - 1].insert(2,s).pop_back(); //update locationDisplays
		
		display();
	}
}

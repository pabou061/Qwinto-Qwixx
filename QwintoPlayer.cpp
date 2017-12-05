#include "QwintoPlayer.h"
#include <vector>
#include <iostream>
#include <locale>
#include <string>
#include <algorithm>

void QwintoPlayer::inputBeforeRoll(RollOfDice &_rollOfDice) {
	std::vector<Dice> SelectedColors;
	std::string input = "";
	bool hasBlue = false;
	bool hasRed = false;
	bool hasYellow = false;
	std::locale loc;

	std::cout << "Select the die or the dice that you desire to roll and type \"done\" at the end: " << std::endl;

	while (input != "done" || SelectedColors.size() == 0) {
		std::cin >> input;

		std::transform(input.begin(), input.end(), input.begin(), ::tolower);
		if (input == "blue" && !hasBlue)
		{
			SelectedColors.push_back(Dice(Colour(BLUE)));
			hasBlue = true;
		}
		else if (input == "red" && !hasRed)
		{
			SelectedColors.push_back(Dice(Colour(RED)));
			hasRed = true;
		}
		else if (input == "yellow" && !hasYellow)
		{
			SelectedColors.push_back(Dice(Colour(YELLOW)));
			hasYellow = true;
		}
		else if (input != "done") {
			std::cout << "input invalid" << std::endl;

		}
		else if (SelectedColors.size() == 0) {
			std::cout << "input invalid" << std::endl;
		}
	}
	_rollOfDice = RollOfDice(SelectedColors);
}


void QwintoPlayer::inputAfterRoll(RollOfDice &_rollOfDice) {


	
	bool isDone = false;
	std::locale loc;
	std::vector<Dice> SelectedColors;


	while (!isDone) {
		int number = 0;
		std::string input = "";
		int input2 = "";
		std::cout << "Please select the row color where you would like to place your score" << std::endl;

		if (!isPlaying) {
			std::cout << "NOTE: You can type \"pass\" to skip with no penalty "<< std::endl;

		}
		if (isPlaying) {
			std::cout << "NOTE: You can type \"fail\" to mark a failed throw " << std::endl;
		}


		std::cin >> input;

		std::transform(input.begin(), input.end(), input.begin(), ::tolower);

		if (input != "fail" && input != "pass") {
		
			while (number < 1 || number >9) {
				std::cout << "Please select the column number (between 1 and 9) where you would like to place your score: " << std::endl;
				std::cin >> input2;
				
				if (std::cin.fail()) {
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				}
				else {
					number = std::stoi(input2);
				}
				if (number < 1 || number>9)
				{
					std::cout << "invalid number" << std::endl;
				}

			}
		}
		number--;

		if (input == "fail" && isPlaying)
		{
			q.failedAttempts++;
			isDone = true;
		}
		else if (input == "pass" && !isPlaying)
		{
			// do nothing
			isDone = true;
		}
		else if (input == "red") // check if the color is in the roll
		{
			if (q.score(_rollOfDice, RED, number)) {
				q.r[number] = _rollOfDice;
				isDone = true;
			}


			//add to scoresheet and then validate?
		}
		else if (input == "yellow")
		{
			if (q.score(_rollOfDice, YELLOW, number)) {
				q.y[number] = _rollOfDice;
				isDone = true;
			}
		}
		else if (input == "blue") {
			if (q.score(_rollOfDice, BLUE, number)) {
				q.b[number] = _rollOfDice;
				isDone = true;
			}
		}
		if(!isDone) {
			std::cout << "invalid input" << std::endl;
		}

	}
}

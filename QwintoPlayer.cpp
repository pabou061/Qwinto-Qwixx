#include "QwintoPlayer.h"
#include <vector>
#include <iostream>
#include <locale>
#include <string>
#include <algorithm>

// La fonction prend comme argument un RollOfDice
// on prend un input du joueur puis on initialise les dés d'apres son choix
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

// La fonction prend comme argument un RollOfDice
// On check ce que le joueur veut faire apres un roll 
void QwintoPlayer::inputAfterRoll(RollOfDice &_rollOfDice) {


	
	bool isDone = false;
	std::locale loc;
	std::vector<Dice> SelectedColors;


	while (!isDone) {
		int number = 0;
		std::string input = "";
		int input2 = 0;
		// on choisi la ligne ou on veux mettre le score
		std::cout << "Please select the row color where you would like to place your score" << std::endl;
		// s'il n'a pas lancé le dé alors il peut passer sans penalité
		if (!isPlaying) {
			std::cout << "NOTE: You can type \"pass\" to skip with no penalty "<< std::endl;

		}
		// s'il a lancé le dé, il peut faire un fail pour avoir un failed attempt
		if (isPlaying) {
			std::cout << "NOTE: You can type \"fail\" to mark a failed throw " << std::endl;
		}


		std::cin >> input;

		std::transform(input.begin(), input.end(), input.begin(), ::tolower);

		if (input != "fail" && input != "pass") {
		// on choisi la colonne 
			while (number < 1 || number >10) {
				std::cout << "Please select the column number (between 1 and 10) where you would like to place your score: " << std::endl;
				std::cin >> number;
				
				if (std::cin.fail()) {
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				}
				if (number < 1 || number>10)
				{
					std::cout << "invalid number" << std::endl;
				}

			}
		}
		number--;
		// s'il a fait un fail on incremente failed attempts 
		if (input == "fail" && isPlaying)
		{
			q.failedAttempts++;
			isDone = true;
		}
		// s'il fait un pass, on termine le tour
		else if (input == "pass" && !isPlaying)
		{
			// do nothing
			isDone = true;
		}
		// s'il a choisi la ligne rouge, on check si c'est valide puis on score
		else if (input == "red") 
		{
			if (q.score(_rollOfDice, RED, number)) {
				q.r[number] = _rollOfDice;
				isDone = true;
			}

		}
		// s'il a choisi la ligne jaune, on check si c'est valide puis on score
		else if (input == "yellow")
		{
			if (q.score(_rollOfDice, YELLOW, number)) {
				q.y[number] = _rollOfDice;
				isDone = true;
			}
		}
		// s'il a choisi la ligne bleu, on check si c'est valide puis on score
		else if (input == "blue") {
			if (q.score(_rollOfDice, BLUE, number)) {
				q.b[number] = _rollOfDice;
				isDone = true;
			}
		}
		// s'il y a une erreur dans son choix on ne laisse pas son tour terminer
		if(!isDone) {
			std::cout << "invalid input" << std::endl;
		}

	}
}

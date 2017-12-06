#include "QwixxPlayer.h"
#include <iostream>
#include <vector>


// Cette fonction prend comme argument un RollOfDice
//On initialise les 6 Dice qu'on a besion pour faire le roll
void QwixxPlayer::inputBeforeRoll(RollOfDice &_rollOfDice)
{
	std::vector<Dice> SelectedColors;
	SelectedColors.push_back(Dice(Colour(BLUE)));
	SelectedColors.push_back(Dice(Colour(RED)));
	SelectedColors.push_back(Dice(Colour(YELLOW)));
	SelectedColors.push_back(Dice(Colour(GREEN)));
	SelectedColors.push_back(Dice(Colour(WHITE)));
	SelectedColors.push_back(Dice(Colour(WHITE)));

	_rollOfDice = RollOfDice(SelectedColors);
}

// Cette fonction prend comme argument un RollOfDice
// On check ce que le joueur veut faire apres un roll 
void QwixxPlayer::inputAfterRoll(RollOfDice &_rollOfDice) {

	std::string input = "";
	int input2 = 0;
	int number = 0;
	bool isDone = false;
	std::locale loc;
	std::vector<Dice> SelectedColors;
	int counter = 0;


	// isPlaying: On check si c'est le tour du joueur qui a lancé le Dice
	if (isPlaying)
	{
		bool colorDone = false;
		bool whiteDone = false;
		int i;
		int wNumber = 0;


		std::vector<Dice> vDice;
		// On check dans quelle ligne il veux mettre le score pour son Colored Dice et son White dice
		while (!colorDone) {
			std::cout << "Please select the row color where you would like to place your score using the die of the color you select" << std::endl;
			std::cout << "NOTE: You can type \"pass\" to skip this section if you have realised that you cannot score " << std::endl;
			std::cin >> input;
			std::transform(input.begin(), input.end(), input.begin(), ::tolower);
			if (input == "pass") {
				colorDone = true;

			}
			else {

				i = 1;
				//on imprime les dés blancs pour qu'il puisse choisir quel dé il veut
				for (Dice d6 : _rollOfDice) {
					if (d6.c == WHITE) {
						std::cout << i << ":" << d6;

						i++;
					}
				}
				// on check quel dé blanc il veux choisir
				while (wNumber != 1 && wNumber != 2) {
					std::cout << "Please enter the number of the white die that you desire :";

					std::cin >> wNumber;

					if (std::cin.fail()) {
						std::cin.clear();
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					}
					else {
						std::cout << std::endl;
						//wNumber = std::stoi(input2);
					}

					if (wNumber != 1 && wNumber != 2) {
						std::cout << "invalid number" << std::endl;
					}
					else {
						vDice.push_back(_rollOfDice.d.at(wNumber + 3));

					}
				}
				// s'il a choisi le dé rouge on l'ajoute a rd puis on check si c'est valide
				if (input == "red") 
				{
					vDice.push_back(_rollOfDice.d.at(1));
					RollOfDice rd = RollOfDice(vDice);
					if (q.score(rd, RED)) {
						try
						{
							q.r += rd;
							colorDone = true;
							counter++;
						}
						catch (const std::exception&)
						{

						}
					}
				}
				// s'il a choisi le dé jaune on l'ajoute a rd puis on check si c'est valide
				else if (input == "yellow")
				{
					vDice.push_back(_rollOfDice.d.at(2));
					RollOfDice rd = RollOfDice(vDice);
					if (q.score(rd, YELLOW)) {

						try
						{
							q.y += rd;
							colorDone = true;
							counter++;
						}
						catch (const std::exception&)
						{

						}
					}
				}
				// s'il a choisi le dé bleu on l'ajoute a rd puis on check si c'est valide
				else if (input == "blue") {
					vDice.push_back(_rollOfDice.d.at(0));
					RollOfDice rd = RollOfDice(vDice);
					if (q.score(rd, BLUE)) {

						try
						{
							q.b += rd;
							colorDone = true;
							counter++;
						}
						catch (const std::exception&)
						{

						}
					}
				}
				// s'il a choisi le dé vert on l'ajoute a rd puis on check si c'est valide
				else if (input == "green") {
					vDice.push_back(_rollOfDice.d.at(3));
					RollOfDice rd = RollOfDice(vDice);
					if (q.score(rd, GREEN)) {
						try
						{
							q.g += rd;
							colorDone = true;
							counter++;
						}
						catch (const std::exception&)
						{

						}
					}
				}
				else {
					std::cout << "invalid input" << std::endl;
				}
				vDice.clear();

			}


		}
		// on met les dés blanc dans un nouveau RollOfDice et on attend si le joueur veux mettre un score avec
		// les 2 dés blancs
		std::vector<Dice> whiteDice;
		for (Dice d6 : _rollOfDice) {
			if (d6.c == WHITE) {
				whiteDice.push_back(d6);
			}
		}
		RollOfDice rd = RollOfDice(whiteDice);

		while (!whiteDone) {
			std::cout << "Please select the row color where you would like to place your score using the 2 white dice" << std::endl;
			std::cout << "NOTE: You can type \"pass\" to skip this section if you have realised that you cannot score " << std::endl;
			std::cin >> input;
			std::transform(input.begin(), input.end(), input.begin(), ::tolower);

			//s'il ne veux pas, on termine la boucle while
			if (input == "pass")
			{
				whiteDone = true;
			}
			// s'il a choisi la ligne rouge, on check si c'est valide puis on score
			else if (input == "red") 
			{
				if (q.score(rd, RED)) {
					try
					{
						q.r += rd;
						whiteDone = true;
						counter++;
					}
					catch (const std::exception&)
					{

					}

				}

			}
			// s'il a choisi la ligne jaune, on check si c'est valide puis on score
			else if (input == "yellow")
			{
				if (q.score(rd, YELLOW)) {
					try
					{
						q.y += rd;
						whiteDone = true;
						counter++;
					}
					catch (const std::exception&)
					{

					}
				}
			}
			// s'il a choisi la ligne bleue, on check si c'est valide puis on score
			else if (input == "blue") {
				if (q.score(rd, BLUE)) {
					try
					{
						q.b += rd;
						whiteDone = true;
						counter++;
					}
					catch (const std::exception&)
					{

					}
				}
			}
			// s'il a choisi la ligne vert, on check si c'est valide puis on score
			else if (input == "green") {
				if (q.score(rd, GREEN)) {
					try
					{
						q.g += rd;
						whiteDone = true;
						counter++;
					}
					catch (const std::exception&)
					{

					}
				}
			}
			if (!whiteDone)
				std::cout << "invalid input" << std::endl;



		}



		if (counter <= 0)  q.failedAttempts++;
	}// fin isPlaying 



	// else: le tour des autres joueurs
	else {
		// choisir dans quelle ligne ils veulent mettre leur score
		while (!isDone) {
			std::cout << "Please select the row color where you would like to place your score" << std::endl;
			std::cout << "NOTE: You can type \"pass\" to skip with no penalty " << std::endl;
			std::cin >> input;
			std::transform(input.begin(), input.end(), input.begin(), ::tolower);

			std::vector<Dice> vD;
			vD.push_back(_rollOfDice.d.at(4));

			vD.push_back(_rollOfDice.d.at(5));
			RollOfDice rd(vD);

			// s'ils ne veulent pas mettre un score
			if (input == "pass" && !isPlaying)
			{
				
				isDone = true;
			}
			// s'il a choisi la ligne rouge, on check si c'est valide puis on score
			else if (input == "red")
			{
				if (q.score(rd, RED)) {
					try
					{
						q.r += rd;
						isDone = true;
					}
					catch (const std::exception&)
					{

					}

				}


			}
			// s'il a choisi la ligne jaune, on check si c'est valide puis on score
			else if (input == "yellow")
			{
				if (q.score(rd, YELLOW)) {
					try
					{
						q.y += rd;
						isDone = true;
					}
					catch (const std::exception&)
					{

					}
				}
			}
			// s'il a choisi la ligne bleue, on check si c'est valide puis on score
			else if (input == "blue") {
				if (q.score(rd, BLUE)) {
					try
					{
						q.b += rd;
						isDone = true;
					}
					catch (const std::exception&)
					{

					}
				}
			}
			// s'il a choisi la ligne vert, on check si c'est valide puis on score
			else if (input == "green") {
				if (q.score(rd, GREEN)) {
					try
					{
						q.g += rd;
						isDone = true;
					}
					catch (const std::exception&)
					{

					}
				}
			}
			//s'il n'a pas bein choisie la ligne on imprime une erreur
			if (!isDone)
				std::cout << "invalid input" << std::endl;

		}

	}
	q.updateLock();
}



#include "Dice.h"
#include "RollOfDice.h"
#include <iostream>
#include <list>
#include "QwintoRow.h"
#include "QwixxRow.h"
#include "QwintoPlayer.h"
#include "QwixxPlayer.h"
#include "player.h"
#include "QwixxScoreSheet.h"
#include "QwintoScoreSheet.h"
#include "ScoreSheet.h"
#include <vector>
#include <string>
int main() {

	std::string gameversion = "";
	int nbPlayers = 0;
	std::vector<std::string> namePlayers;
	std::string pname;
	std::vector<QwixxPlayer> xPlayer;
	std::vector<QwintoPlayer> oPlayer;
	RollOfDice rd;
	bool done = false;
	int turn = 0;
	int currentPlayer = 0;
	int wScore = -21;
	std::string wName;

	// le joueur choisi quelle version il veux
	while (gameversion != "qwixx" && gameversion != "qwinto") {
		std::cout << "Choose the game you want: qwinto or qwixx" << std::endl;
		std::cin >> gameversion;
		std::transform(gameversion.begin(), gameversion.end(), gameversion.begin(), ::tolower);
	}



	// le joueur chosi le nombre de joueurs
	while (nbPlayers < 1 || nbPlayers >3)
	{
		std::cout << "\nPlease enter the amount of players: \n";
		std::cin >> nbPlayers;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}


	}




	// le joueir choisi les noms des joueurs
	std::cout << "Type the name of the player" << std::endl;
	for (size_t i = 0; i < nbPlayers; i++)
	{
		std::cout << "Player " << i + 1 << std::endl;
		std::cin >> pname;
		namePlayers.push_back(pname);

	}
	// versioon qwixx
	if (gameversion == "qwixx")
	{
		//initialisation des Player et Scoresheet
		for (size_t i = 0; i < nbPlayers; i++)
		{
			QwixxScoreSheet q(namePlayers.at(i));
			
/*	TESTING PART - uncomment to add values
			for (size_t i = 0; i < 5; i++)
			{
				q.y.rScore[i] = 1;
				q.r.rScore[i] = 1;

			}
*/
			xPlayer.push_back(QwixxPlayer(namePlayers.at(i), q));
		}


		while (!done) {
			// tour du Current player
			currentPlayer = turn % nbPlayers;
			QwixxPlayer &cp = xPlayer.at(currentPlayer);
			cp.isPlaying = true;
			std::cout << cp.q;
			cp.inputBeforeRoll(rd);
			rd.roll();
			std::cout << rd;
			cp.inputAfterRoll(rd);
			cp.q.setTotal();
			std::cout << cp.q;

			//lock une ligne pour tous les joueurs s'il y a 5 numbers dans une ligne
			for (size_t i = 0; i < 4; i++) {
				if (cp.q.isLocked[i]) {
					for (size_t j = 0; j < nbPlayers; j++) {
						xPlayer.at(j).q.isLocked[i] = true;
					}
				}
			}
			// loop pour le tour des autres joueurs
			for (size_t i = 0; i < nbPlayers; i++)
			{
				if (currentPlayer != i) {
					std::cout << xPlayer.at(i).q;
					xPlayer.at(i).inputAfterRoll(rd);
					xPlayer.at(i).q.setTotal();
					std::cout << xPlayer.at(i).q;
				}

			}
			//lock une ligne pour tous les joueurs s'il y a 5 numbers dans une ligne
			for (size_t i = 0; i < nbPlayers; i++) {
				for (size_t k = 0; k < 4; k++) {
					if (xPlayer.at(i).q.isLocked[k]) {
						for (size_t j = 0; j < nbPlayers; j++) {
							xPlayer.at(j).q.isLocked[i] = true;
						}
					}
				}
			}
			//check si quelqu'un a gagné
			for (size_t i = 0; i < nbPlayers; i++)
			{
				if (!xPlayer.at(i).q) {
					done = true;
				}

			}
			//change turn
			cp.isPlaying = false;
			turn++;
		}

		//print scores
		for (size_t i = 0; i < nbPlayers; i++)
		{
			xPlayer.at(i).q.setTotal();
			std::cout << xPlayer.at(i).q;
			if (xPlayer.at(i).q.currScore > wScore) {
				wScore = xPlayer.at(i).q.currScore;
				wName = xPlayer.at(i).name;
			}
		}

		std::cout << "Winner: " << wName << " with a score of: " << wScore << std::endl;




	}
	else {

		//initialisation des Player et Scoresheet
		for (size_t i = 0; i < nbPlayers; i++)
		{
			QwintoScoreSheet q(namePlayers.at(i));
/*	TESTING PART - uncomment to add values
			for (size_t i = 0; i < 9; i++)
			{
			q.y[i] = 1;
			q.r[i] = 1;
			q.b[i] = 1;

			}
*/
			oPlayer.push_back(QwintoPlayer(namePlayers.at(i), q));
		}


		while (!done) {
			//current player turn
			currentPlayer = turn % nbPlayers;
			QwintoPlayer &cp = oPlayer.at(currentPlayer);
			cp.isPlaying = true;
			std::cout << cp.q;
			cp.inputBeforeRoll(rd);
			rd.roll();
			std::cout << rd;
			std::cout << cp.q;
			cp.inputAfterRoll(rd);
			cp.q.setTotal();
			std::cout << cp.q;
			//tour des autres joueurs
			for (size_t i = 0; i < nbPlayers; i++)
			{
				if (currentPlayer != i) {
					std::cout << oPlayer.at(i).q;
					oPlayer.at(i).inputAfterRoll(rd);
					oPlayer.at(i).q.setTotal();
					std::cout << oPlayer.at(i).q;
				}

			}
			//stop si quelqu'un a gagné
			for (size_t i = 0; i < nbPlayers; i++)
			{
				if (!oPlayer.at(i).q) {
					done = true;
				}

			}
			//next turn
			cp.isPlaying = false;
			turn++;
		}
		//print scores
		for (size_t i = 0; i < nbPlayers; i++)
		{
			oPlayer.at(i).q.setTotal();
			std::cout << oPlayer.at(i).q;
			if (oPlayer.at(i).q.currScore > wScore) {
				wScore = oPlayer.at(i).q.currScore;
				wName = oPlayer.at(i).name;
			}
		}

		std::cout << "Winner: " << wName << " with a score of: " << wScore << std::endl;




	}

}


#include "QwixxPlayer.h"
#include <iostream>
#include <vector>



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

void QwixxPlayer::inputAfterRoll(RollOfDice &_rollOfDice) {

	std::string input = "";
	int input2 = 0;
	int number = 0;
	bool isDone = false;
	std::locale loc;
	std::vector<Dice> SelectedColors;
	int counter = 0;



	if (isPlaying)
	{
		bool colorDone = false;
		bool whiteDone = false;
		int i;
		int wNumber = 0;


		while (!isDone) {
			std::cout << "Would you like to score using your die of color and a white die? Please enter yes or no. " << std::endl;
			std::cin >> input;
			std::transform(input.begin(), input.end(), input.begin(), ::tolower);

			if (input == "yes" && !colorDone) {
				std::vector<Dice> vDice;
				while (!colorDone) {
					std::cout << "Please select the row color where you would like to place your score" << std::endl;
					std::cout << "NOTE: You can type \"pass\" to skip this section if you have realised that you cannot score " << std::endl;
					std::cin >> input;
					std::transform(input.begin(), input.end(), input.begin(), ::tolower);
					if (input == "pass") {
						colorDone = true;

					}
					else {

						i = 1;
						for (Dice d6 : _rollOfDice) {
							if (d6.c == WHITE) {
								std::cout << i << ":" << d6;

								i++;
							}
						}
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
						if (input == "red") // check if the color is in the roll
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


							//add to scoresheet and then validate?
						}
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

			}
			else if (!whiteDone) {
				std::vector<Dice> whiteDice;
				for (Dice d6 : _rollOfDice) {
					if (d6.c == WHITE) {
						whiteDice.push_back(d6);
					}
				}
				RollOfDice rd = RollOfDice(whiteDice);
				while (!whiteDone) {
					std::cout << "Please select the row color where you would like to place your score";
					std::cout << "NOTE: You can type \"pass\" to skip this section if you have realised that you cannot score " << std::endl;
					std::cin >> input;
					std::transform(input.begin(), input.end(), input.begin(), ::tolower);


					if (input == "pass")
					{
						whiteDone = true;
					}
					else if (input == "red") // check if the color is in the roll
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


						//add to scoresheet and then validate?
					}
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
			}
			if (whiteDone && colorDone) {
				isDone = true;
			}
		}

		if (counter <= 0)  q.failedAttempts++;
	}




	else {
		while (!isDone) {
			std::cout << "Please select the row color where you would like to place your score" << std::endl;
			std::cout << "NOTE: You can type \"pass\" to skip with no penalty " << std::endl;
			std::cin >> input;
			std::transform(input.begin(), input.end(), input.begin(), ::tolower);
			
			std::vector<Dice> vD;
			vD.push_back(_rollOfDice.d.at(4));
			
			vD.push_back(_rollOfDice.d.at(5));
			RollOfDice rd(vD);

			if (input == "pass" && !isPlaying)
			{
				// do nothing
				isDone = true;
			}
			else if (input == "red") // check if the color is in the roll
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


				//add to scoresheet and then validate?
			}
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
			if (!isDone)
				std::cout << "invalid input" << std::endl;

		}

	}
	q.updateLock();
}



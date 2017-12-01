#pragma once
#include "Player.h"
#include "QwixxScoreSheet.h"

class QwixxPlayer : Player {

	QwixxScoreSheet q;
	
	QwixxPlayer(std::string _name, QwixxScoreSheet _scoreSheet) : Player(_name), q(_scoreSheet) {};
	void inputBeforeRoll(RollOfDice &_rollOfDice);
	void inputAfterRoll(RollOfDice &_rollOfDice);


};	
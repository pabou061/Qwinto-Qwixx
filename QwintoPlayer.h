#pragma once
#include "Player.h"
#include "QwintoScoreSheet.h"

class QwintoPlayer : Player {

	QwintoScoreSheet q;

	QwintoPlayer(std::string _name, QwintoScoreSheet _scoreSheet) : Player(_name), q(_scoreSheet) {};
	void inputBeforeRoll(RollOfDice &_rollOfDice);
	void inputAfterRoll(RollOfDice &_rollOfDice);
};
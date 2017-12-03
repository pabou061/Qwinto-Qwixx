#pragma once
#include "Player.h"
#include "QwintoScoreSheet.h"

class QwintoPlayer : public Player {
public:
	QwintoScoreSheet q;

	QwintoPlayer(std::string _name, QwintoScoreSheet _scoreSheet) : Player(_name), q(_scoreSheet) { isPlaying = false; };
	void inputBeforeRoll(RollOfDice &_rollOfDice);
	void inputAfterRoll(RollOfDice &_rollOfDice);
};
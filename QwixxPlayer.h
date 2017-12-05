#pragma once
#include "Player.h"
#include "QwixxScoreSheet.h"

class QwixxPlayer : public Player {
public:
	QwixxScoreSheet q;
	
	QwixxPlayer(std::string _name, QwixxScoreSheet _scoreSheet) : Player(_name), q(_scoreSheet) { isPlaying = false; };
	void inputBeforeRoll(RollOfDice &_rollOfDice);
	void inputAfterRoll(RollOfDice &_rollOfDice);


};	
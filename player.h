#pragma once

#include "RollOfDice.h"
class Player {
	bool isPlaying;
	virtual void inputBeforeRoll(RollOfDice r);
	virtual void inputAfterRoll(RollOfDice r);

};
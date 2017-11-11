#pragma once
#include <string>
#include "RollOfDice.h"
#include "Colour.h"
class ScoreSheet
{
public:
	std::string playername;
	int failedAttempts, score;

	inline ScoreSheet() :failedAttempts(0), score(0) {}
	void score(RollOfDice, Colour selectedC, int positionL = -1);
	
	~ScoreSheet();
};


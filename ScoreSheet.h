#pragma once
#include <string>
#include "RollOfDice.h"
#include "Colour.h"
#include <ostream>
class ScoreSheet
{
public:
	std::string playername;
	int failedAttempts, currScore;

	ScoreSheet();
	bool score(RollOfDice, Colour selectedC, int positionL = -1);
	//int virtual calcTotal();
	void setTotal();
	//virtual bool const operator!();
	friend std::ostream& operator<<(std::ostream& out, ScoreSheet s);



	~ScoreSheet();
protected:
	void validate();
};


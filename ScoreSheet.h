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
	ScoreSheet(std::string name);
	bool score(RollOfDice rd, Colour selectedC, int positionL = -1);
	int virtual calcTotal()=0;
	void setTotal();
	virtual bool const operator!();
	//friend std::ostream& operator<<(std::ostream& out, ScoreSheet s);

	~ScoreSheet();
protected:
	bool virtual validate(RollOfDice rd, Colour selectedC, int positionL = -1);
};


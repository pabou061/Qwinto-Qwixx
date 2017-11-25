#include "ScoreSheet.h"

ScoreSheet::~ScoreSheet()
{
}

bool ScoreSheet::score(RollOfDice rd, Colour selectedC, int positionL = -1) {
	return validate(rd, selectedC, positionL );
}


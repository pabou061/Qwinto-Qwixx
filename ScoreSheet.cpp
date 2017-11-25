#include "ScoreSheet.h"

ScoreSheet::~ScoreSheet()
{
}

bool ScoreSheet::validate(RollOfDice rd, Colour selectedC, int positionL)
{
	return false;
}



ScoreSheet::ScoreSheet()
{
}

bool ScoreSheet::score(RollOfDice rd, Colour selectedC, int positionL ) {
	return validate(rd, selectedC, positionL );
}

bool const ScoreSheet::operator!()
{
	return nullptr;
}


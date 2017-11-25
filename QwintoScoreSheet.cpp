#include "QwintoScoreSheet.h"
#include <string>

QwintoScoreSheet::QwintoScoreSheet(std::string name) {
	QwintoRow<RED> r();
	QwintoRow <BLUE> b();
	QwintoRow <YELLOW> y();
	playername = name;
	failedAttempts = 0;
	currScore = 0;

}

int calcTotal();
void setTotal();
bool const operator!();
friend std::ostream& operator<<(std::ostream& out, ScoreSheet s);

~QwintoScoreSheet();

bool validate(RollOfDice rd, Colour selectedC, int positionL = -1){
	if (positionL == -1)
		return false;

	for (Dice d : rd) {
		if (d.c != selectedC)
			return false;
	}
	switch (selectedC)
	{
	case RED:
		if (positionL == 3) 
			return false; 
		else 
			return r.validate(rd, positionL);
	case YELLOW:
		break;
	case BLUE:
		break;
	default:
		return false;
	}

	return true;
}
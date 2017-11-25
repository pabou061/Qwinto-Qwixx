#include "QwintoScoreSheet.h"
#include <string>

QwintoScoreSheet::QwintoScoreSheet(std::string name) {
	QwintoRow <RED> r();
	QwintoRow <BLUE> b();
	QwintoRow <YELLOW> y();
	playername = name;
	failedAttempts = 0;
	currScore = 0;

}

int QwintoScoreSheet::calcTotal()
{
	return 0;
}

bool const QwintoScoreSheet::operator!()
{
	return nullptr;
}

bool QwintoScoreSheet::validate(RollOfDice rd, Colour selectedC, int positionL) {


	for (Dice d : rd) {
		if (d.c != selectedC)
			return false;
	}
	switch (selectedC)
	{
	case RED:
		return r.validate(rd, positionL);
	case YELLOW:
		return	y.validate(rd, positionL);

	case BLUE:
		return b.validate(rd, positionL);
	default:
		return false;
	}
	return true;
}
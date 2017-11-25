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

	if (failedAttempts == 4) {
		return true;
	}
	int counter = 0;
	for (size_t i = 0; i < 10; i++)
	{
		if (r[i] == 0 && i != 3)
		{
			counter++;
			break;
		}
	}

	for (size_t i = 0; i < 10; i++)
	{
		if (y[i] == 0 && i != 5)
		{
			counter++;
			break;
		}
	}
	for (size_t i = 0; i < 10; i++)
	{
		if (b[i] == 0 && i != 4)
		{
			counter++;
			break;
		}
	}

	return false;
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
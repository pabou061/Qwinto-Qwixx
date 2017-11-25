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
	int total = 0;
	int counter = 0;


	total -= failedAttempts * 5;

	for (size_t i = 0; i < 10; i++)
	{
		if (r[i] > 0 && i != 3)
		{
			counter++;

		}
	}
	counter == 9 ? total += r[9] : total += counter;
	counter = 0;

	for (size_t i = 0; i < 10; i++)
	{
		if (y[i] > 0 && i != 5)
		{
			counter++;

		}
	}
	counter == 9 ? total += y[9] : total += counter;
	counter = 0;
	for (size_t i = 0; i < 10; i++)
	{
		if (b[i] > 0 && i != 4)
		{
			counter++;
		}
	}
	counter == 9 ? total += b[9] : total += counter;
	counter = 0;

	for (size_t i = 2; i < 10; i++)
	{
		if (b[i] > 0 && y[i - 1] > 0 && r[i - 2] > 0) {
			switch (i)
			{
			case 2:
				total += b[i];
				break;
			case 3:
				total += r[i - 2];
				break;
			case 7:
				total += r[i - 2];
				break;
			case 8:
				total += y[i - 1];
				break;
			case 9:
				total += b[i];
				break;
			default:
				break;
			}
		}
	}

	return total;
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
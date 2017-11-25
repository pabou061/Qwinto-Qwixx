#include "QwixxScoreSheet.h"
#include <vector>
#include <list>
#include <string>

QwixxScoreSheet::QwixxScoreSheet(std::string name) {

	QwixxRow <std::vector<int>, RED> r();
	QwixxRow <std::list<int>, BLUE> b();
	QwixxRow <std::vector<int>, YELLOW> y();
	QwixxRow <std::list<int>, GREEN> g();
	playername = name;
	failedAttempts = 0;
	currScore = 0;
	for (int i = 0; i < 4; i++)
		isLocked[i] = false;

}

int QwixxScoreSheet::calcTotal()
{
	return 0;
}

void QwixxScoreSheet::setTotal()
{
	currScore = calcTotal();
}

bool const QwixxScoreSheet::operator!()
{
	if (failedAttempts == 4)
	{
		return false;
	}
	int counter = 0;
	for (int i = 0; i < 4; i++) {
		if (isLocked[i])
			counter++;
	}
	return counter >= 2 ? true : false;
}

QwixxScoreSheet::~QwixxScoreSheet()
{
}

bool QwixxScoreSheet::validate(RollOfDice rd, Colour selectedC, int positionL)
{

	for (Dice d : rd) {
		if (d.c != selectedC || d.c!= WHITE)
			return false;
	}

	switch (selectedC)
	{
	case RED:
		if (isLocked[0]) return false;
		break;
	case YELLOW:
		if (isLocked[1]) return false;
		break;
	case GREEN:
		if (isLocked[2]) return false;
		break;
	case BLUE:
		if (isLocked[3]) return false;
		break;
	default:
		return false;
	}
	return true;
}

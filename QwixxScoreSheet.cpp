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
	int total = 0;
	total -= failedAttempts * 5;

	for (size_t i = 0; i < 11; i++)
	{
		total += r.rScore[i] + y.rScore[i];
	}

	for (int i : b.rScore) {
		total += i;
	}
	for (int i : g.rScore) {
		total += i;
	}
	return total;
}

void QwixxScoreSheet::setTotal()
{
	currScore = calcTotal();
}

bool const QwixxScoreSheet::operator!()
{
	if (failedAttempts == 4)
	{
		return true;
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
		if (d.c != selectedC || d.c != WHITE)
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

std::ostream & operator<<(std::ostream & out, QwixxScoreSheet s)
{
	out << "Player name: " << s.playername << "\t Points: " << s.currScore << std::endl;
	out << "\t-----------------------------------" << std::endl;
	out << s.r;
	char c = s.isLocked[0] ? 'L' : 'U';
	out << c << std::endl;
	out << "\t-----------------------------------" << std::endl;
	out << s.y;
	c = s.isLocked[1] ? 'L' : 'U';
	out << c << std::endl;
	out << "\t-----------------------------------" << std::endl;
	out << s.g;
	c = s.isLocked[2] ? 'L' : 'U';
	out << c << std::endl;
	out << "\t-----------------------------------" << std::endl;
	out << s.b;
	c = s.isLocked[3] ? 'L' : 'U';
	out << c << std::endl;
	out << "\t-----------------------------------" << std::endl;
	out << "Failed throws: " << s.failedAttempts << std::endl;
	return out;
}

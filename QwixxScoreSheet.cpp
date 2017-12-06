#include "QwixxScoreSheet.h"
#include <vector>
#include <list>
#include <string>

//initialisation d'un ScoreSheet pour un joueur
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

// function qui calcul le total pour le joueur
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

// public funtion qui appelle calcTotal()
void QwixxScoreSheet::setTotal()
{
	currScore = calcTotal();
}
// fonction qui check si le jeu est fini: 4 failed attempts ou 2 lignes terminées
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
// s'il y a une ligne qui est locked car on a 5 scores, on la met Locked pour tous les joueurs
void QwixxScoreSheet::updateLock()
{
	int counter1 = 0;
	int counter2 = 0;
	for (int i = 0; i < 11; i++) {
		if (r.rScore[i] > 0) {
			counter1++;
		}
		if (y.rScore[i] > 0) {
			counter2++;
		}
	}
	if (counter1 >= 5) {
		isLocked[0] = true;
	}
	if (counter2 >= 5) {
		isLocked[1] = true;
	}
	counter1 = 0;
	counter2 = 0;
	for (int i : b.rScore) {
		if (i > 0) {
			counter1++;
		}
	}
	for (int i : g.rScore) {
		if (i > 0) {
			counter1++;
		}
	}
	if (counter1 >= 5) {
		isLocked[2] = true;
	}
	if (counter2 >= 5) {
		isLocked[3] = true;
	}

}

// validation si la ligne est locked (il y a 5 scores dans une ligne)
bool QwixxScoreSheet::validate(RollOfDice rd, Colour selectedC, int positionL)
{

	for (Dice d : rd) {
		if (d.c != selectedC && d.c != WHITE)
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

//override print function
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

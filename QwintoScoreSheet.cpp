#include "QwintoScoreSheet.h"
#include <string>

// initialisation d'un ScoreSheet pour un Player
QwintoScoreSheet::QwintoScoreSheet(std::string name) {
	QwintoRow <RED> r();
	QwintoRow <BLUE> b();
	QwintoRow <YELLOW> y();
	playername = name;
	failedAttempts = 0;
	currScore = 0;

}

//fonntion qui calcule le total pour un joueur
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

// public function qui appelle calcTotal()
void QwintoScoreSheet::setTotal() {
	currScore= calcTotal();
}

// fonction qui check si le jeu est terminé: 4 failed attempts ou 2 lignes qui sont remplies
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
	return counter <= 1 ? true : false;
}

QwintoScoreSheet::~QwintoScoreSheet()
{
}

//fonction qui check si le score que le joueur veux mettre dans une case est valide
bool QwintoScoreSheet::validate(RollOfDice rd, Colour selectedC, int positionL) {

	bool isCorrect = false;
	for (Dice d : rd) {
		if (d.c == selectedC)
			isCorrect =true;
	}

	if (!isCorrect)
	{
		return false;
	}
	switch (selectedC)
	{
	case RED:
		if (positionL == 8 && y[9] == rd)
		{
			return false;
		}
		else if (positionL < 8 && (y[positionL - 1] == rd || b[positionL - 2] == rd)) {
			return false;
		}
		return r.validate(rd, positionL);
	case YELLOW:
		if ((positionL == 9 && r[8] == rd) || (positionL == 0 && b[1] == rd))
		{
			return false;
		}
		else if (positionL < 9 && (r[positionL - 1] == rd || b[positionL + 1] == rd)) {
			return false;
		}
		return	y.validate(rd, positionL);
	case BLUE:
		if (positionL == 1 && y[0] == rd)
		{
			return false;
		}
		else if (positionL > 1 && (y[positionL + 1] == rd || r[positionL + 2] == rd)) {
			return false;
		}

		return b.validate(rd, positionL);
	default:
		return false;
	}
	return true;
}

//override print function
 std::ostream & operator<<(std::ostream & out, QwintoScoreSheet s)
 {
	 out << "Player name: " << s.playername << "\t Points: " << s.currScore << std::endl;
	 out << "\t\t-------------------------------" << std::endl;
	 out << s.r;
	 out << "\t     ----------------------------------" << std::endl;
	 out << s.y;
	 out << "\t -----------------------------------" << std::endl;
	 out << s.b;
	 out << "\t --------------------------------" << std::endl;
	 out << "Failed throws: " << s.failedAttempts << std::endl;
	 return out;
 }

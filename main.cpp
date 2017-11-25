#include "Dice.h"
#include "RollOfDice.h"
#include <iostream>
#include <list>
#include "QwintoRow.h"
#include "QwixxRow.h"
int main() {
	Colour b = WHITE;
	Dice c(b);
	Dice d(b);
	Dice e(b);
	QwintoRow<RED> qrr;
	QwintoRow<YELLOW> qyy;
	QwintoRow<BLUE> qbb;
	QwixxRow<std::vector<int>, RED> qxx;
	std::cout << qxx;
	std::vector<Dice>dV = { c,d };
	
	std::vector<Dice>dE = { c,c,c,c,c,c,c,c,c,c,c,c,c };

	RollOfDice z(dV);
	RollOfDice z1(dE);
	z1.roll();
	z.roll();
	qxx += z;
	qxx += z;
	std::cout << qxx;
	return 0;
}
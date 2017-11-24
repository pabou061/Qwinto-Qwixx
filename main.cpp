#include "Dice.h"
#include "RollOfDice.h"
#include <iostream>
#include "QwintoRow.h"
#include "QwixxRow.h"
int main() {
	Colour b = RED;
	Dice c(b);
	Dice d(b);
	Dice e(b);
	QwintoRow<RED> qrr;
	QwintoRow<YELLOW> qyy;
	QwintoRow<BLUE> qbb;
	
	std::vector<Dice>dV = { c,d,e };
	std::vector<Dice>dE = { c,c,c,c,c,c,c,c,c,c,c,c,c };

	RollOfDice z(dV);
	RollOfDice z1(dE);
	z1.roll();
	z.roll();
	std::cout << z;
	int awignahan = z;
	std::cout << awignahan;
	std::cout << qrr.validate(z,0) << std::endl;
	std::cout << qrr.validate(z,10) << std::endl;
	qrr[0] = z;
	std::cout << qrr.validate(z,0) << std::endl;
	std::cout << qrr.validate(z1,1) << std::endl;
	std::cout << qrr;
	std::cout << qyy;
	std::cout << qbb;
	return 0;
}
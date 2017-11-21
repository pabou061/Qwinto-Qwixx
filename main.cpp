#include "Dice.h"
#include "RollOfDice.h"
#include <iostream>
int main() {
	Colour b = RED;
	Dice c(b);
	Dice d(b);
	std::vector<Dice>dV = { c,d };

	RollOfDice z(dV);
	z.roll();
	std::cout << z;
	int awignahan = z;
	std::cout << awignahan;
	for (int i = 0; i < 500; i++) {
		z.roll();
		std::cout << z;
	}


	return 0;
}
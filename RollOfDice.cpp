#include "RollOfDice.h"

std::ostream & operator<<(std::ostream & out, RollOfDice const & obj)
{
	out << "This roll of dice contains the following dice: " << std::endl;
	for (Dice d6 : obj) {
		out << d6;
		
	}
	out << std::endl;
	return out;
}

RollOfDice::RollOfDice(std::vector<Dice> vD) :d(vD) {}


void RollOfDice::roll()
{
	for (Dice& d6 : *this) {
		d6.roll();
	}
}

RollOfDice RollOfDice::pair(Dice d1, Dice d2)
{
	std::vector<Dice> tmp = { d1,d2 };
	return RollOfDice(tmp);
}

RollOfDice::operator int() const
{
	int sum = 0;
	for (Dice d6 : *this) {
		sum += d6.getFace();
	}
	return sum;
}

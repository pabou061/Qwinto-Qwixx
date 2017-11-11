#pragma once
#ifndef DICE_H
#define DICE_H
#include "Colour.h"
#include <ostream>


class Dice{ 
	const Colour c;
	int face;
	int roll();

	inline Dice(Colour colour) : c(colour) { roll(); }
	inline friend std::ostream& operator<<(std::ostream& out, Dice const& obj) { return out << obj.face; }

};

#endif
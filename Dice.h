#pragma once
#ifndef DICE_H
#define DICE_H
#include "Colour.h"
#include <ostream>
#include <random>

struct RandomDice
{
public:
	int getRandom();
private:
	unsigned random = distribution(mersenne_generator);
	static std::random_device seed_generator;
	static unsigned seed;
	static std::mt19937 mersenne_generator;
	static std::uniform_int_distribution<unsigned> distribution;
};


class Dice{
public:
	const Colour c;
	int face;
	int roll();

	RandomDice rdice;

	inline Dice(Colour colour):c(colour) {};
	inline friend std::ostream& operator<<(std::ostream& out, Dice const& obj) { return out << obj.face; }

};

#endif
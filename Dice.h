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
	
	static std::random_device seed_generator;
	static unsigned seed;
	static std::mt19937 mersenne_generator;
	static std::uniform_int_distribution<unsigned> distribution;
};


class Dice{
private:
	int face;
public:
	const Colour c;
	int roll();

	RandomDice rdice;
	inline Dice() :c(RED) {}; //needed that for a test might pull it out.
	inline Dice(Colour colour):c(colour) {};
	inline friend std::ostream& operator<<(std::ostream& out, Dice const& obj) { return out << obj.face; }
	inline int getFace() { return face; }
	//inline friend bool operator==(Dice d6, Dice d) { return d6.c == d.c && d6.getFace() == d.getFace(); }
	

};

#endif
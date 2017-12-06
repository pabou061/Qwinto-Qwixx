#include "Dice.h"

std::random_device RandomDice::seed_generator;
unsigned RandomDice::seed = seed_generator();
std::uniform_int_distribution<unsigned> RandomDice::distribution(1, 6);
std::mt19937 RandomDice::mersenne_generator(RandomDice::seed);

int RandomDice::getRandom() {
	return distribution(mersenne_generator);
}
int Dice::roll(){ 
	face = rdice.getRandom(); //we need a random number from randomdice and we set it to face for the roll
	return face;
}


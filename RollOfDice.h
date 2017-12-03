#pragma once
#include <vector>
#include <algorithm>
#include "Dice.h"
class RollOfDice {
public:
	std::vector<Dice> d;
	RollOfDice(std::vector<Dice> vD);
	RollOfDice() {};
	void roll();
	operator int() const;
	RollOfDice pair(Dice d1, Dice d2);
	friend std::ostream& operator<<(std::ostream& out, RollOfDice const& obj);
	inline std::vector<Dice>::iterator begin() {
		return d.begin();
	}
	inline std::vector<Dice>::iterator end() {
		return d.end();
	}
	inline std::vector<Dice>::const_iterator begin() const {
		return d.begin();
	}
	inline std::vector<Dice>::const_iterator end() const {
		return d.end();
	}
	//inline void addDice(Dice d6) {
		//d.push_back(d6);
	//}
	//inline void removeDice(Dice d6) {
		//d.erase(std::remove(d.begin(), d.end(), d6), d.end()); //TODO : rework this or scrap it.
	//}
	
};
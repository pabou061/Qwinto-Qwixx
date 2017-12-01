
#include "RollOfDice.h"
#include <string>

class Player {
public:
	std::string name;
	bool isPlaying;
	Player() {};
	Player(std::string _name) { name = _name; };
	virtual void inputBeforeRoll(RollOfDice &_rollOfDice);
	virtual void inputAfterRoll(RollOfDice &_rollOfDice);
	
};
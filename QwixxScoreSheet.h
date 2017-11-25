#pragma once

#include "ScoreSheet.h"
#include "QwixxRow.h"
#include <string>
#include <list>

class QwixxScoreSheet : ScoreSheet {

	QwixxRow <std::vector<int>, RED> r;
	QwixxRow <std::list<int>, BLUE> b;
	QwixxRow <std::vector<int>, YELLOW> y;
	QwixxRow <std::list<int>, GREEN> g;
	bool isLocked[4];

	QwixxScoreSheet(std::string name);

	int virtual calcTotal() ;
	void setTotal();
	bool const operator!();
	//friend std::ostream& operator<<(std::ostream& out, ScoreSheet s);

	~QwixxScoreSheet();
protected:
	bool validate(RollOfDice rd, Colour selectedC, int positionL = -1);

};


#pragma once

#include "ScoreSheet.h"
#include <string>
#include "QwintoRow.h"

class QwintoScoreSheet : ScoreSheet {

public:
	QwintoRow <RED> r;
	QwintoRow <BLUE> b;
	QwintoRow <YELLOW> y;

	QwintoScoreSheet(std::string name);

	int calcTotal();
	void setTotal();
	bool virtual const operator!();
	 friend std::ostream& operator<<(std::ostream& out, QwintoScoreSheet s);

	~QwintoScoreSheet();
protected:
	bool validate(RollOfDice rd, Colour selectedC, int positionL = -1);

};
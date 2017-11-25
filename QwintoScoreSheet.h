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
	bool const operator!();
	friend std::ostream& operator<<(std::ostream& out, ScoreSheet s);

	~QwintoScoreSheet();
protected:
	bool validate(RollOfDice rd, Colour selectedC, int positionL = -1);

};
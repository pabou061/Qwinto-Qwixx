#pragma once

#include "ScoreSheet.h"
#include "QwintoRow.h"
class QwintoScoreSheet : ScoreSheet {

public:
	QwintoRow <RED> r;
	QwintoRow <BLUE> b;
	QwintoRow <YELLOW> y;


	QwintoScoreSheet();

	bool score(RollOfDice, Colour selectedC, int positionL = -1);
	int calcTotal();
	void setTotal();
	bool const operator!();
	friend std::ostream& operator<<(std::ostream& out, ScoreSheet s);

	~QwintoScoreSheet();
protected:
	void validate();

};
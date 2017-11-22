#pragma once
#include "Colour.h"
#include "RollOfDice.h"

template <Colour C> class QwintoRow {
public:
	int rScore[12];
	inline int& operator[] (int x) {
		return rScore[x];
	}
	inline QwintoRow() { for (int i = 0; i < 12; i++){rScore[i] = 0; } };
	bool validate(RollOfDice rd, int pos);
};



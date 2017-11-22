#include "QwintoRow.h"
#include "Colour.h"
#include "RollOfDice.h"
#define macro = return true;

bool QwintoRow<RED>::validate(RollOfDice rd, int pos) {
	if (pos < 0) { return false; }
	if (pos > 12) { return false; }
	for (int i = 0; i < pos; i++) {
		if (rScore[i] <= 0) {
			return false;
		}
	}
	return rScore[pos - 1] < rd && rScore[pos] == 0;
}
bool QwintoRow<GREEN>::validate(RollOfDice rd, int pos) {
	if (pos < 0) { return false; }
	if (pos > 12) { return false; }
	for (int i = 0; i < pos; i++) {
		if (rScore[i] <= 0) {
			return false;
		}
	}
	return rScore[pos - 1] < rd && rScore[pos] == 0;
}
bool QwintoRow<YELLOW>::validate(RollOfDice rd,int pos) {
	if (pos < 0) { return false; }
	if (pos > 12) { return false; }
	for (int i = 0; i < pos; i++) {
		if (rScore[i] <= 0) {
			return false;
		}
	}
	return rScore[pos - 1] < rd && rScore[pos] == 0;
}
bool QwintoRow<BLUE>::validate(RollOfDice rd,int pos) {
	if (pos < 0) { return false; }
	if (pos > 12) { return false; }
	for (int i = 0; i < pos; i++) {
		if (rScore[i] <= 0) {
			return false;
		}
	}
	return rScore[pos - 1] < rd && rScore[pos] == 0;
}

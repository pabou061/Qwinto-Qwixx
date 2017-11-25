#include "QwintoRow.h"
#include "Colour.h"
#include "RollOfDice.h"
#include <ostream>

bool QwintoRow<RED>::validate(RollOfDice rd, int pos) {
	if (pos < 0) { return false; }
	if (pos > 12) { return false; }
	if (pos == 3) return false;
	for (int i = 0; i < pos; i++) {
		if (i != 3) {
			if (rScore[i] <= 0) {
				return false;
			}
		}
	}
	return rScore[pos - 1] < rd && rScore[pos] == 0;
}
bool QwintoRow<YELLOW>::validate(RollOfDice rd, int pos) {
	if (pos < 0) { return false; }
	if (pos > 12) { return false; }
	if (pos == 5) { return false; }
	for (int i = 0; i < pos; i++) {
		if (i != 5) {
			if (rScore[i] <= 0) {
				return false;
			}
		}
	}
	return rScore[pos - 1] < rd && rScore[pos] == 0;
}
bool QwintoRow<BLUE>::validate(RollOfDice rd, int pos) {
	if (pos < 0) { return false; }
	if (pos > 12) { return false; }
	if (pos == 4) { return false; }
	for (int i = 0; i < pos; i++) {
		if (i != 4) {
			if (rScore[i] <= 0) {
				return false;
			}
		}
	}
	return rScore[pos - 1] < rd && rScore[pos] == 0;
}

std::ostream& operator<<(std::ostream& out, QwintoRow<RED> qRow)
	{
			out << "Red" << "             ";
			for (int i = 0; i < 11; i++) {
				switch (i) {
				case 0:
					out << "|";
					break;
				case 1:
					out << "%";
					break;
				case 2:
					out << "%";
					break;
				case 3:
					out << "|XX";
					break;
				case 5:
					out << "%";
					break;
				case 6:
					out << "%";
					break;
				default:
					out << "|";
					break;
				}
				if (i != 3 && i != 10) {
					if (qRow.rScore[i] > 9) { out << qRow.rScore[i]; }
					else if (qRow.rScore[i] < 10 && qRow.rScore[i] != 0) { out << " " << qRow.rScore[i]; }
					else { out << "  "; }
				}
			}
			out << std::endl;
			return out;
	}

std::ostream & operator<<(std::ostream & out, QwintoRow<BLUE> qRow)
{
	out << "Blue" << "      ";
	for (int i = 0; i < 11; i++) {
		switch (i) {
		case 4:
			out << "|XX";
			break;
		case 2:
			out << "%";
			break;
		case 3:
			out << "%";
			break;
		case 9:
			out << "%";
			break;
		case 10:
			out << "%";
			break;
		default:
			out << "|";
			break;
		}
		if (i != 4 && i != 10) {
			if (qRow.rScore[i] > 9) { out << qRow.rScore[i]; }
			else if (qRow.rScore[i] < 10 && qRow.rScore[i] != 0) { out << " " << qRow.rScore[i]; }
			else { out << "  "; }
		}
	}
	out << std::endl;
	return out;
}

std::ostream & operator<<(std::ostream & out, QwintoRow<YELLOW> qRow)
{
	out << "Yellow" << "       ";
	for (int i = 0; i < 11; i++) {
		switch (i) {
		case 5:
			out << "|XX";
			break;
		case 7:
			out << "%";
			break;
		case 8:
			out << "%";
			break;
		default:
			out << "|";
			break;
		}
		if (i != 5 && i != 10) {
			if (qRow.rScore[i] > 9) { out << qRow.rScore[i]; }
			else if (qRow.rScore[i] < 10 && qRow.rScore[i] != 0) { out << " " << qRow.rScore[i]; }
			else { out << "  "; }
		}
	}
	out << std::endl;
	return out;
}


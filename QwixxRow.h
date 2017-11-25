#pragma once
#include "Colour.h"
#include <ostream>
#include "RollOfDice.h"
template<class T,const  Colour colour> class QwixxRow {
	public:
		T rScore;
		

		void print(std::ostream & output) const;
		QwixxRow<T,colour> operator+=(RollOfDice rd);
		QwixxRow();
};



template<class T, Colour colour>
std::ostream & operator<<(std::ostream & out, QwixxRow<T, colour>& qxx)
{
	qxx.print(out);
	return out;
};

template<class T, Colour colour>
void QwixxRow<T, colour>::print(std::ostream & out) const
{
	if (colour == RED) { out << "Red     "; }
	else if (colour == BLUE) { out << "Blue    "; }
	else if (colour == YELLOW) { out << "Yellow  "; }
	else { out << "Green    "; }
	int i = 2;
	for (int b : rScore) {
		out << "|";	
				if (b > 0) { out << "XX"; }
				else{
					if (i < 10) { out << " " << i; }
					else { out << i; }
				}
				i++;
	}
	out << "|";


}

template<class T, Colour colour>
QwixxRow<T,colour> QwixxRow<T, colour>::operator+=(RollOfDice rd)
{
	int counter = 0;
	for (Dice d : rd) {
		if (d.c != colour && d.c != WHITE) {
			throw "Not White of the color of the Row";
			return *this;
		}
		counter++;
	}
	if (counter != 2) {
		return *this;
	}
	int vd = rd;
	counter = 0;
	for (int  i : rScore) {
		if (vd > counter) {}
		else if(i != 0) {
			throw "There are scores at the right of where you want to put your score";
			return *this;
		}
		counter++;
	}
	counter = 0;
	for (int & i : rScore) {
		if (vd == counter) {
			if (i != 0) {
				throw "There is a score where you are trying to put your score";
				return *this;
			}
			else {
				i = vd;
				return *this;
			}
		}
		counter++;
	}
	return *this;
}

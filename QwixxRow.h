#pragma once
#include "Colour.h"
#include <ostream>
#include "RollOfDice.h"
#include <algorithm>
//this template allows for std::vector as a class and a colour
template<class T,const  Colour colour> class QwixxRow { 
	public:
		T rScore;
		

		void print(std::ostream & output) const; //we use a print function to make our live easier
		QwixxRow<T,colour> operator+=(RollOfDice rd);
		QwixxRow();
};



template<class T, Colour colour>
std::ostream & operator<<(std::ostream & out, QwixxRow<T, colour>& qxx)
{
	qxx.print(out); //call print that puts the contents of scoresheet in the ostream out
	return out;
};
//we use this template to allow any color to be treated
template<class T, Colour colour>
void QwixxRow<T, colour>::print(std::ostream & out) const
{
	//we check the colour and add text to signify which row it is and with the appropriate number of spaces for the spacing with the scoresheet
	if (colour == RED) { out << "Red     "; }
	else if (colour == BLUE) { out << "Blue    "; }
	else if (colour == YELLOW) { out << "Yellow  "; }
	else { out << "Green   "; }
	//2-12 for red and yellow so it's a bit different depending on the color
	if (colour == RED || colour == YELLOW) {
		int i = 2;
		for (int b : rScore) {
			out << "|";
			if (b > 0) { out << "XX"; }
			else {
				if (i < 10) { out << " " << i; }
				else { out << i; }
			}
			i++;
		}
	}
	//12-2 for the other 2 colours. so we start with 12 and go down
	else {
		int i = 12;
		for (int b : rScore) {
			out << "|";
			if (b > 0) { out << "XX"; }
			else {
				if (i < 10) { out << " " << i; }
				else { out << i; }
			}
			--i;
		}
	}
	out << "|";
	//close the field.

}
//doable for std::vector and std::list and any color
template<class T, Colour colour>
QwixxRow<T,colour> QwixxRow<T, colour>::operator+=(RollOfDice rd)
{
	int counter = 0;
	//check for whether the color is the one of the row or white and check if the RollOfDice has 2 dice
	for (Dice d : rd) {
		if (d.c != colour && d.c != WHITE) {
			throw "Not White of the color of the Row";
			
		}
		counter++;
	}

	if (counter != 2) {
		throw "Your roll does not have 2 dice";
	}
	int vd = rd;
	int pos;
	//depending on the colour the position of the number changes so the next if-else block checks that issue and makes sure the number is the position on the dice.
	if (colour == RED || colour == YELLOW) {
		pos = vd - 2;
	}
	else {
		pos = std::abs(vd - 2 - 10);
	}
	//check if there are scores at the right of the position
	counter = 0;
	for (int  i : rScore) {
		if (pos > counter) {}
		else if(i != 0) {
			throw "There are scores at the right of where you want to put your score";
			
		}
		counter++;
	}
	//check if pos contains anything
	counter = 0;
	for (int & i : rScore) { //using a reference to be able to change the number there
		if (pos == counter) {
			if (i != 0) {
				throw "There is a score where you are trying to put your score";
				
			}
			else {
				i = vd; //puts the score in
				return *this;
			}
		}
		counter++;
	}
	return *this;
}

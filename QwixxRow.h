#pragma once
#include "Colour.h"
#include <ostream>
template<class T,const  Colour colour> class QwixxRow {
	public:
		T rScore;
		

		void print(std::ostream & output) const;

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
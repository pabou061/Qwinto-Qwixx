#include "QwixxRow.h"
#include <vector>
#include <list>



QwixxRow<std::vector<int>,RED>::QwixxRow() {
	rScore = std::vector<int>(11, 0);
}


QwixxRow<std::vector<int>, YELLOW>::QwixxRow() {
	rScore = std::vector<int>(11, 0);
}

QwixxRow<std::list<int>, BLUE>::QwixxRow() {
	rScore = std::list<int>(11, 0);
}

QwixxRow<std::list<int>, GREEN>::QwixxRow() {
	rScore = std::list<int>(11, 0);
}



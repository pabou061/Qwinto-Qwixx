#include "QwixxRow.h"
#include <vector>
#include <list>



QwixxRow<std::vector<int>,RED>::QwixxRow() {
	rScore = std::vector<int>(12, 0);
}

QwixxRow<std::vector<int>, BLUE>::QwixxRow() {
	rScore = std::vector<int>(12, 0);
}
QwixxRow<std::vector<int>, YELLOW>::QwixxRow() {
	rScore = std::vector<int>(12, 0);
}
QwixxRow<std::vector<int>, WHITE>::QwixxRow() {
	rScore = std::vector<int>(12, 0);
}
QwixxRow<std::vector<int>, GREEN>::QwixxRow() {
	rScore = std::vector<int>(12, 0);
}

QwixxRow<std::list<int>, RED>::QwixxRow() {
	rScore = std::list<int>(12, 0);
}

QwixxRow<std::list<int>, BLUE>::QwixxRow() {
	rScore = std::list<int>(12, 0);
}
QwixxRow<std::list<int>, YELLOW>::QwixxRow() {
	rScore = std::list<int>(12, 0);
}
QwixxRow<std::list<int>, WHITE>::QwixxRow() {
	rScore = std::list<int>(12, 0);
}
QwixxRow<std::list<int>, GREEN>::QwixxRow() {
	rScore = std::list<int>(12, 0);
}



#include "QwixxScoreSheet.h"
#include <vector>
#include <list>
#include <string>

QwixxScoreSheet::QwixxScoreSheet(std::string name) {

	QwixxRow <std::vector<int>,RED> r();
	QwixxRow <std::list<int>,BLUE> b();
	QwixxRow <std::vector<int>,YELLOW> y();
	QwixxRow <std::list<int>,GREEN> g();
	playername = name;
	failedAttempts = 0;
	currScore = 0;

}
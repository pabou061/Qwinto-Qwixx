#pragma once

#include "ScoreSheet.h"
#include "QwixxRow.h"
#include <string>
#include <list>

class QwixxScoreSheet : ScoreSheet {

	QwixxRow <std::vector<int>, RED> r;
	QwixxRow <std::list<int>, BLUE> b;
	QwixxRow <std::vector<int>, YELLOW> y;
	QwixxRow <std::list<int>, GREEN> g;

	QwixxScoreSheet(std::string name);
};
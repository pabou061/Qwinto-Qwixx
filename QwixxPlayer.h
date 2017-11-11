#pragma once
#include "Player.h"
#include "QwixxScoreSheet.h"

class QwixxPlayer :Player {

	QwixxScoreSheet q;
	virtual void inputBeforeRoll();
	virtual void inputAfterRoll();

};
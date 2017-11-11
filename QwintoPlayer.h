#pragma once
#include "Player.h"
#include "QwintoScoreSheet.h"

class QwintoPlayer :Player {

	QwintoScoreSheet q;
	virtual void inputBeforeRoll();
	virtual void inputAfterRoll();

};
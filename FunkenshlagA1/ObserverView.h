#pragma once
#include <iostream>
#include "GameTurnSubject.h"
#include <string>

class ObserverView {
private:
	int phase;
	int step;
	shared_ptr<Player> playersTurn;
	GameTurnSubject gameTurn;


	string playerMessage;
	string phaseMessage;
	string stepMessage;


public:
	void update(shared_ptr<Player>,int, int);
	void displayeView();
};
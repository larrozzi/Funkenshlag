#pragma once
#include <iostream>
#include "GameTurnSubject.h"
#include <string>
#include "Player.h"

class GameTurnSubject;

class ObserverView {
private:
	GameTurnSubject* gameTurn;
	int phase;
	int step;
	std::shared_ptr<Player> playersTurn;


	string playerMessage;
	string phaseMessage;
	string stepMessage;


public:
	void update(std::shared_ptr<Player>,int, int);
	void displayView();
};
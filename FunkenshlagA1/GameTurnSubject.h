#pragma once
#include <vector>
#include "ObserverView.h"
#include "Player.h"

class GameTurnSubject {
private:
	std::vector<ObserverView*> views;
	int phase;
	int step;
	shared_ptr<Player> playersTurn;
public:
	void regist(ObserverView*);
	void notifyObserver();
	
	//setters
	void setStep(int);
	void setPhase(int);
	void setPlayersTurn(shared_ptr<Player>);
};
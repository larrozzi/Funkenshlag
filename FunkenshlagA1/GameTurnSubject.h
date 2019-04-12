#pragma once
#include <vector>
#include "ObserverView.h"
#include "Player.h"

class ObserverView;

class GameTurnSubject {
private:
	std::vector<ObserverView*> views;
	int phase;
	int step;
	shared_ptr<Player> playersTurn;
public:
	void regist(ObserverView*);
	void notifyObserver();
	GameTurnSubject();
	GameTurnSubject(shared_ptr<Player> pl,int,int);
	
	//setters
	void setStep(int);
	void setPhase(int);
	void setPlayersTurn(shared_ptr<Player>);
};
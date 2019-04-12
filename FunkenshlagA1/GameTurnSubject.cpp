#include "GameTurnSubject.h"
#include "ObserverView.h"

GameTurnSubject::GameTurnSubject(shared_ptr<Player> pl,int phase,int step) {
	this->playersTurn = pl;
	this->phase = phase;
	this->step = step;
}
GameTurnSubject::GameTurnSubject() {
	phase = 1;
	step = 1;
	playersTurn = NULL;
}

void GameTurnSubject::regist(ObserverView* view)
{
	views.push_back(view);
	notifyObserver();
}

void GameTurnSubject::notifyObserver()
{
	for (int i = 0; i < views.size();i++) {
		views[i]->update(playersTurn,phase,step);
	}	
}

void GameTurnSubject::setStep(int newStep)
{
	this->step = newStep;
	notifyObserver();
}

void GameTurnSubject::setPhase(int newPhase)
{
	this->phase = newPhase;
	notifyObserver();
}

void GameTurnSubject::setPlayersTurn(shared_ptr<Player> newPlayer)
{
	this->playersTurn = newPlayer;
	notifyObserver();
}


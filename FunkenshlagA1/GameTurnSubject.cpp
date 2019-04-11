#include "GameTurnSubject.h"

void GameTurnSubject::regist(ObserverView* view)
{
	views.push_back(view);
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


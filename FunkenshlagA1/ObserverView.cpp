#include "ObserverView.h"

void ObserverView::update(shared_ptr<Player> newPlayer, int newPhase, int newStep)
{
	this->playersTurn = newPlayer;
	this->phase = newPhase;
	this->step = newStep;

	switch (phase) {
	case 1:
		phaseMessage = "~~~DETERMINING TURN ORDER PHASE~~~";
		break;
	case 2:
		phaseMessage = "~~~POWER PLANT AUCTION PHASE~~~\nIn this phase players take turns taking part in the Power Plant Aunction\n";
		break;
	case 3:
		phaseMessage = "~~~RESOURCE BUYING PHASE~~~\nIn this phase players take turns buying any number of resources from the Resource Market\n";
		break;
	case 4:
		phaseMessage = "~~~BUILDING PHASE~~~\nIn this phase players take turns building houses in cities within the chosen regions\n";
		break;
	case 5:
		phaseMessage = "~~~BEREAUCRACY~~~\nIn this phase players earn elektro, the Resource Market is resupplied, and the Power Plant Market is shuffled.\n";
		break;
	}

	stepMessage = "CURRENT STEP: " + step;
	playerMessage = "CURRENT PLAYER TURN: " + playersTurn->getName();

	this->displayView();
}

void ObserverView::displayView()
{
	std::cout << stepMessage << phaseMessage << playerMessage;
}



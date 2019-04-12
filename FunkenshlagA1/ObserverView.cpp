#include "ObserverView.h"
#include "GameTurnSubject.h"

ObserverView::ObserverView(GameTurnSubject* gameTurn) {
	gameTurn->regist(this);
}


void ObserverView::update(shared_ptr<Player> newPlayer, int newPhase, int newStep)
{
	this->playersTurn = newPlayer;
	this->phase = newPhase;
	this->step = newStep;

	switch (phase) {
	case 1:
		phaseMessage = "\nCURRENT PHASE: " + std::to_string(phase) + "\n~~~DETERMINING TURN ORDER PHASE~~~";
		break;
	case 2:
		phaseMessage = "\nCURRENT PHASE: " + std::to_string(phase) + "\n~~~POWER PLANT AUCTION PHASE~~~\nIn this phase players take turns taking part in the Power Plant Aunction";
		break;
	case 3:
		phaseMessage = "\nCURRENT PHASE: " + std::to_string(phase) + "\n~~~RESOURCE BUYING PHASE~~~\nIn this phase players take turns buying any number of resources from the Resource Market";
		break;
	case 4:
		phaseMessage = "\nCURRENT PHASE: " + std::to_string(phase) + "\n~~~BUILDING PHASE~~~\nIn this phase players take turns building houses in cities within the chosen regions";
		break;
	case 5:
		phaseMessage = "\nCURRENT PHASE: " + std::to_string(phase) + "\n~~~BEREAUCRACY~~~\nIn this phase players earn elektro, the Resource Market is resupplied, and the Power Plant Market is shuffled.";
		break;
	}

	stepMessage = "CURRENT STEP: " + std::to_string(step);
	playerMessage = "CURRENT PLAYER TURN: " + playersTurn->getName() + "  elektro: " + std::to_string(playersTurn->getElektro()) + "\n";

	this->displayView();
}

void ObserverView::displayView()
{
	std::cout << stepMessage << std::endl << phaseMessage << std::endl << playerMessage;
}



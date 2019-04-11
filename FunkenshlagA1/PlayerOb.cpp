#include "GameMapOb.h"
#include "GameMap.h"
#include "Player.h"
#include "PlayerOb.h"
#include <iostream>

using namespace std;
PlayerOb::PlayerOb() {};

PlayerOb::PlayerOb(Player* s)
{
	_subject = s;
	_subject->Attach(this);
};
PlayerOb::~PlayerOb()
{
	_subject->Detach(this);
};
void PlayerOb::Update()
{
	Display();
};
void PlayerOb::Display()
{
	cout << _subject->getName() << " has " << _subject->getElektro() << " Electro." << endl;
	cout << _subject->getName() << " has " << _subject->getCoalHeld() << " Coal," << _subject->getOilHeld() << " Oil," <<
	_subject->getGarbageHeld() << " Garbage," << _subject->getUraniumHeld() << " Uranium." << endl;


};


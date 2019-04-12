#include "GameMapOb.h"
#include "GameMap.h"
#include "Player.h"
#include "PlayerOb.h"
#include <iostream>
#include "House.h"

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
	cout << _subject->getName() << endl;
	cout << " has " <<  _subject->getElektro() << " Electro." << endl;
	cout << " has " << _subject->getCoalHeld() << " Coal," << _subject->getOilHeld() << " Oil," <<
	_subject->getGarbageHeld() << " Garbage," << _subject->getUraniumHeld() << " Uranium." << endl;
	
	for (int i = 0; i < _subject->getOwnedHouses().size(); i++)
	{
		cout <<"Owns a house in " << _subject->getOwnedHouses().at(i).getCity() << endl;
	}

};
//Player* pointer1 = &p1;
//PlayerOb ob1 = PlayerOb(pointer1);
//Player* pointer2 = &p2;
//PlayerOb ob2 = PlayerOb(pointer2);
//Player* pointer3 = &p3;
//PlayerOb ob3 = PlayerOb(pointer3);

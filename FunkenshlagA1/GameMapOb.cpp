#include "GameMapOb.h"
#include "GameMap.h"
#include <iostream>
using namespace std;
GameMapOb::GameMapOb() {};

GameMapOb::GameMapOb(GameMap* s) 
{
	_subject = s;
	_subject->Attach(this);
};
GameMapOb::~GameMapOb() 
{
	_subject->Detach(this);
};
void GameMapOb::Update()
{
	Display();
};
void GameMapOb::Display()
{
	for (int i = 0; i < _subject->getActiveMap().size(); i++)
	{
		cout << _subject->getActiveMap().at(i).getName();

		for (auto& elem : _subject->getActiveMap().at(i).getOwners())
		{
			std::cout << elem.first << " " << elem.second.first << " " << elem.second.second << "\n";
		}
	}
}


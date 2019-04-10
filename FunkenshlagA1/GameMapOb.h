#pragma once
#include "Observer.h"
#include "Player.h"
#include "GameMap.h"

class GameMapOb : public Observer
{
	public:
		GameMapOb();
		GameMapOb(GameMap* s);
		~GameMapOb();

		void Update();
		void Display();

	private:
		GameMap *_subject;


};
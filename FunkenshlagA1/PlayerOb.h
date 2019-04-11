#pragma once
#include "Observer.h"
#include "Player.h"
#include "GameMap.h"

class PlayerOb : public Observer
{
public:
	PlayerOb();
	PlayerOb(Player* s);
	~PlayerOb();

	void Update();
	void Display();

private:
	Player *_subject;


};
#include <stdio.h>
#include <iostream>
#include <string>
#include "Building.h"
#include "Player.h"
#include "MapLoader.h"
#include "GameMap.h"
#include "ResourceMarket.h"


int main() {
	ResourceMarket* market = new ResourceMarket();
	std::cout << *market << std::endl;
	Player *p1 = new Player("Anthony", 50, RED);
	shared_ptr<PowerPlantCards> card = make_shared<PowerPlantCards>(3, COAL, 2, 3, 1);
	p1->OwnPowerPlant(card);

	int buyAmount = 0;
	string tempType = "";
	Type type = NONE;
	

	cout << "What type of resource would you like to buy?(COAL,OIL,GARBAGE,URANIUM): ";
	getline(cin,tempType);
	type = stringToType(tempType);
	cout << "How many resources would you like to buy?: ";
	cin >> buyAmount;

	p1->buyResource(type,buyAmount, market);

	

	system("pause");
}
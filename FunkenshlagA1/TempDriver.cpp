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
	shared_ptr<PowerPlantCards> card = make_shared<PowerPlantCards>(3, COAL, 4, 100, 1);
	shared_ptr<PowerPlantCards> card1 = make_shared<PowerPlantCards>(3, OIL, 4,100, 1);
	shared_ptr<PowerPlantCards> card2 = make_shared<PowerPlantCards>(3, GARBAGE, 4, 100, 1);
	shared_ptr<PowerPlantCards> card3 = make_shared<PowerPlantCards>(3, URANIUM, 4, 100, 1);
	p1->OwnPowerPlant(card);
	p1->OwnPowerPlant(card1);
	p1->OwnPowerPlant(card2);
	p1->OwnPowerPlant(card3);

	int buyAmount = 0;
	string typeS = "";
	string yOn = "";
	Type type = NONE;
	
	cout << "Would you like to buy resources?(Y/N): ";
	getline(cin, yOn);

	while (yOn != "Y" && yOn != "N") {
		cout << "Please input a valid input(Y or N): ";
		getline(cin, yOn);
	}
	while (yOn == "Y") {
		cout << "What type of resource would you like to buy?(COAL,OIL,GARBAGE,URANIUM): ";
		getline(cin, typeS);
		type = stringToType(typeS);

	
		p1->buyResource(type, market);
		
		cout << "Would you like to buy more resources?(Y/N): ";
		cin.ignore();
		getline(cin, yOn);
	}

	cout << *p1 << endl;

	

	system("pause");
	return 0;
}
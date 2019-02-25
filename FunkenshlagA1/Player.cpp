#include "Player.h"
#include <iostream>
#include <string>

using std::auto_ptr;

using std::string;
using std::cout;
using std::endl;
using std::cin;
using std::to_string;

Player::Player()
{
}

Player::Player(string name,  int elektro,  HouseColor _color) : name{name}, elektro{elektro}, _color{_color}
{
}

Player ::~Player()
{
}

inline string Player::getName() const {
	return name;
}

inline void Player::setName(string name) {
	this->name = name;
}

inline int Player::getElektro() const {
	return elektro;
}
inline void Player::setElektro(int elektro) {
	this->elektro = elektro;
}

void Player::OutputPlayerStatus() const {
	string separator = "---------------------------------------------------------------------------------\n";
	string PlayerStatus;
	string msg = separator + name + " has the following items \n" + "\t"+ to_string(getElektro()) + "Elektros" + "\n";

	//print houses 
	PlayerStatus += "He owns "+ houses.size();
	PlayerStatus += " of color " +_color;

	cout << PlayerStatus;
	
	//for (int i = 0; i < houses.size(); i++)
		//PlayerStatus += houses[it].getColor() + ",";
	

	//	//print powerplants 
	//PlayerStatus += msg + " and owns the following Power plants: ";
	//for (int i = 0; i < myPowerPlants.size(); i++)
	//	PlayerStatus += to_string(myPowerPlants[i].getCardValue() )+ ",";
	//PlayerStatus += "\n";

	//print resources

	/*for (int i = 0; i < myPowerPlants.size(); i++)
		PlayerStatus += "Power plant number " + to_string(myPowerPlants[i].getCardValue()) + "has" + myPowerPlants[i].presentresource();
	PlayerStatus += "\n";*/

	// printing each PLayer**
	
}

//************** build houses in cities if possible *****************
//bool Player::BuildHouse(CityNode& city, House& house) {
//	int houseCost = city.getPrice();
//	if (!city.unUse() ) //err :this should return bool
//		return false;
//	else {
//		//elektro -= houseCost;
//		setElektro(getElektro() - houseCost);
//		houses.push_back(house); // add house on vector houses
//		return true;
//	}
//}
// show powerplant in actual market and future market

//************** buy powerplants at auction *****************
//bool Player::bidonPowerPlant(cardDeck& cardDeck, int position, int price) {
//	if (position <= 3 & getElektro() >= price) {
//		setElektro(getElektro() - price);
//		if (myPowerPlants.size() < 3) {
//			AddPowerPlant(cardDeck.GetPlant(position));
//			cardDeck.RemovePlant(position);
//			cardDeck.DrawPlant();
//			return true;
//		}
//	}
//	return false;
//}



//vector <Resource> getRecources() {
//	 return resources;
 //}



 /*bool Player::AddPowerPlant(PowerPlantCards powerplant) {
	 if (myPowerPlants.size() == 3)
		 return false;
	 myPowerPlants.push_back(powerplant);
	 return true;

 }*/

 //void Player::ReplacePowerPlant(auto_ptr<PowerPlant> newplant, int toReplace) {
 //}

//int Player::getHighestPowerPlant() {
//	int max;
//	for (<PowerPlantCards> highestplant : powerplants) {
//		if (highestplant->getPrice() > max)
//			max = highestplant->getPrice();
//	}
//	return max;
//}
//


//********************** buy resources********************
//bool Player::BuyResources(ResourceMarket& rMarket, PowerPlantCards& plant, Resource resource, int amount)
//{
//	int price = rMarket.getPrice(resource, amount);
//	if (amount >= 0 && getElektro() > price &&
//		(plant.getTotalPlacedResources() + amount) <= (2 * plant.getCapacity()) &&
//		rMarket.resource.available()
//		)
//	{
//		plant.placeResource(resource, amount);
//		setElektro(getElektro() - price);
//		rMarket.removeResource(resource, amount);
//		return true;
//	}
//	return false;
//}




//inline std::ostream& operator<<(std::ostream& stream, const Player& player) {
//	stream << player.OutputPlayerStatus();
//}

int main()
{
	//Player player1= new Player(YL, "White", 50);

		//cout << player1;
	
	cout << "Hello and Welcome";

	/*Player PL1 = new Player("Yassine", 50, "blue");

	OutputPlayerStatus();*/

	system("pause");
	return 0;
}
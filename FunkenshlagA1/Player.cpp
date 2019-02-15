#include "PLayer.h"
#include <iostream>

using std::shared_ptr;
using std::string;
using std::vector;
using std::cout;
using std::endl;
using std::cin;
using std::to_string;

Player::Player()
{
}

Player::Player(string name, shared_ptr<HouseColor> color, int elektro)
	:name{ name }, elektro{ elektro }, color{ color }
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

vector <shared_ptr<House>> Player::getHouses() {
	return houses;
}

vector <shared_ptr<PowerPlant>> Player::getPowerplant() {
	return powerplants;
}
//vector <Resource> getRecources() {
//	 return resources;
 //}

bool Player::bidonPowerPlant(cardDeck& cardDeck, int position, int price) {
	if (position <= 3 & getElektro() >= price) {
		setElektro(getElektro() - price);
		//if (powerPlants.size() < 3)
		//AddPowerPlant(cardStack.GetPlant(index));
		cardDeck.RemovePlant(position);
		cardDeck.DrawPlant();
		return true;
	}
	return false;

}

// bool Player::AddPowerPlant(<shared_ptr<PowerPlant>> powerplants) {
 //}

 //void Player::ReplacePowerPlant(<shared_ptr<PowerPlant>> newplant, int toReplace) {
 //}

int Player::getHighestPowerPlant() {
	int max;
	for (std::shared_ptr<PowerPlant> highestplant : powerplants) {
		if (highestplant->getPrice() > max)
			max = highestplant->getPrice();
	}
	return max;
}


shared_ptr<HouseColor> const&  Player::getColor() const {

}


bool Player::BuyResources(ResourceMarket& rMarket, shared_ptr<PowerPlant> plant, Resource resource, int amount)
{
	int price = rMarket.getPrice(resource, amount);
	if (amount >= 0 && getElektro() > price &&
		(plant->getTotalPlacedResources() + amount) <= (2 * plant->getCapacity()) &&
		rMarket.resource.available()
		)
	{
		plant->placeResource(resource, amount);
		setElektro(getElektro() - price);
		rMarket.removeResource(resource, amount);
		return true;
	}
	return false;
}


bool Player::BuildHouse(shared_ptr<City> city, shared_ptr<House>house) {
	int housePrice = city->getPrice();
	if (!city->isOpen() && city->isConnectedto(getHouses())
		return false;

		elektro -= housePrice;
		city->addHouse(house);
		return true;
}
void Player::ShowPlayerStatus() const {
	string separator = "---------------------------------------------------------------------------------\n";

		string msg = separator + name + " with color " + color->getName() + " has" + getElektro() + "Elektros" + "\n";

		//print powerplants 
		PlayerStatus += msg + " he also has these Power plants " +
		for (int i = 0; i < powerplants.size(); i++)
			PlayerStatus += powerplants[i].getValue() + ",";
	PlayerStatus += "\n";

	//print resources
	PlayerStatus += "Powerplant ";
	for (int i = 0; i < powerplants.size(); i++)
		PlayerStatus += powerplants[i].getValue() + "has " + powerplants[i].presentresource();
	PlayerStatus += "\n";

	//print houses 
	PlayerStatus += "Here are the cities he controls: "
		for (int i = 0; i < houses.size(); i++)
			PlayerStatus += houses[i].getName + ",";
	PlayerStatus += "\n";

	// printing each PLayer

   // cout << PlayerStatus
}

inline std::ostream& operator<<(std::ostream& stream, const Player& player) {
	cout << player.ShowPlayerStatus();
}

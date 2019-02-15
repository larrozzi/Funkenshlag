#pragma once

// included dependencies
#include "House.h"

#include "PowerPlantCards.h"
#include "Resource.h"

#include "ResourceMarket.h"
#include <memory>
#include <vector>

using std::shared_ptr;
using std::string;
using std::vector;


class Player
{
private:
	string name;
	int elektro = 50;
	//vector<Resource> resources;
	vector <shared_ptr<House>> houses;
	shared_ptr<HouseColor> color;
	vector<shared_ptr<PowerPlant>> powerplants;

public:
	Player();
	Player(string name, shared_ptr<HouseColor> color, int electro);
	~Player();

	string getName() const;
	void setName(string name);

	int getElektro() const;
	void setElektro(int elektro);

	vector <shared_ptr<House>> getHouses();
	vector <shared_ptr<PowerPlant>> getPowerplant();
	vector <Resource> getRecources();

	bool bidonPowerPlant(cardDeck&);
	bool AddPowerPlant(<shared_ptr<PowerPlant>> powerplants);
	void ReplacePowerPlant(<shared_ptr<PowerPlant>>, int);
	int getHighestPowerPlant();

	shared_ptr<HouseColor> const& getColor() const;

	bool BuyResources(ResourceMarket&, shared_ptr<PowerPlant>, Resource, int);

	bool BuildHouse(shared_ptr<House> house);

	void ShowGameStatus() const;

	inline std::ostream& operator<<(std::ostream& stream, const Player& player);

};
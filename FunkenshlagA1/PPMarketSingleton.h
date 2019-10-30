#pragma once
#include <memory>
#include <vector>
#include "PowerPlantCards.h"

using std::vector;
using std::shared_ptr;

class PPMarketSingleton
{

private:
	static PPMarketSingleton* ppm_instance; //=NULL;

	//constructor
	PPMarketSingleton();

	PPMarketSingleton(PPMarketSingleton const&) = delete;
	void operator=(PPMarketSingleton const&) = delete;

	vector<shared_ptr<PowerPlantCards>> PPlants;  // filled from vector of PP objects inside vector<PowerPlantCards> Pplants 
	//vector<PowerPlantCards> *PPlants; //raw pointer alternative
	vector<shared_ptr<PowerPlantCards>> visiblePPlants;

	int visibleCards = 8;
	int futureMarketPosition = 4;

public:
	//destructor
	~PPMarketSingleton();

	static PPMarketSingleton* GetInstance();  //lazy instantiation
	static void ResetInstance(); //to delete/reset the Singleton

	//getters
	shared_ptr<PowerPlantCards> const getPlant(int index);
	vector<shared_ptr<PowerPlantCards>>& GetPPCards() { return PPlants; }
	vector<shared_ptr<PowerPlantCards>>& GetvisiblePPlants() { return visiblePPlants; }

	//setters
	void SetMPlants(vector<shared_ptr<PowerPlantCards>> PPlants) { this->PPlants = PPlants; };


	void RemovePlant(int index) { visiblePPlants.erase(visiblePPlants.begin() + index); };
	bool DrawPlant();

	//setup the market for the game
	void Setup();

	// method to prints the visible PowerPlantCards
	void printPPmarket(vector<shared_ptr<PowerPlantCards>> visiblePPlants);

	void printPPmarket();
};


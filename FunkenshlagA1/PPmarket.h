#pragma once

#include <memory>
#include <vector>
#include "PowerPlantCards.h"

using std::vector;
using std::shared_ptr;

class PPmarket
{

private:
	vector<shared_ptr<PowerPlantCards>> PPlants; 
	//vector<PowerPlantCards> *PPlants; 
	vector<shared_ptr<PowerPlantCards>> visiblePPlants;
public:
	int visibleCards = 8;
	int futureMarketIndex = 4;

	PPmarket();
	~PPmarket();

	shared_ptr<PowerPlantCards> const GetPlant(int index);
	
	//void SetMPlants(vector<PowerPlantCards> *PPlants) { this->PPlants = PPlants; };

	void SetMPlants(vector<shared_ptr<PowerPlantCards>> PPlants) { this->PPlants = PPlants; }; 

	//	std::vector<std::shared_ptr<Card>>& GetCards() { return cards; }

	vector<shared_ptr<PowerPlantCards>>& GetvisiblePPlants() { return visiblePPlants; }

	void RemovePlant(int index) { visiblePPlants.erase(visiblePPlants.begin() + index); };
	bool DrawPlant();

	// method to prints the visible PowerPlantCards
	void printPPmarket(vector<shared_ptr<PowerPlantCards>> visiblePPlants);
};

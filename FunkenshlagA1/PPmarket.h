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
	vector<shared_ptr<PowerPlantCards>> visiblePPlants;
public:
	int visibleCards = 8;
	int futureMarketIndex = 4;

	PPmarket();
	~PPmarket();

	shared_ptr<PowerPlantCards> const GetPlant(int index);

	void RemovePlant(int index) { visiblePPlants.erase(visiblePPlants.begin() + index); };
	bool DrawPlant();
};


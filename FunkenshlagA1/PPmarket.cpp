#include "PPmarket.h"
#include <algorithm>
#include <memory>

using std::shared_ptr;

PPmarket::PPmarket(){}
PPmarket::~PPmarket(){}


shared_ptr<PowerPlantCards> const PPmarket::GetPlant(int position) {
	if (position < 0 || position >= visiblePPlants.size()) return nullptr;
	return (visiblePPlants[position]);
}

bool PPmarket::DrawPlant() {
	shared_ptr<PowerPlantCards> PPlant = nullptr;

	while (visiblePPlants.size() < visibleCards && PPlants->size() > 0 && PPlant == nullptr) {
		shared_ptr<PowerPlantCards> top = PPlants->at(0);

		// Place card in the visible market
		visiblePPlants.push_back(top);

		PPlants->erase(PPlants->begin());

		std::sort(visiblePPlants.begin(), visiblePPlants.end(), [](shared_ptr<PowerPlantCards> pp1, std::shared_ptr<PowerPlantCards> pp2) { return  (pp1)->getCardValue() < (pp2)->getCardValue(); });
		return true;
	}
	return false;
}

// method to prints the visible PowerPlantCards
void PPmarket::printPPmarket(vector<shared_ptr<PowerPlantCards>> visiblePPlants)
{
	std::vector<shared_ptr<PowerPlantCards>>::iterator show; // create a vector iterator
	for (show = visiblePPlants.begin(); show != visiblePPlants.end(); show++) {
		std::cout << *show << std::endl;
	}
}
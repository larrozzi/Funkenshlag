#include "PPmarket.h"
#include <algorithm>
#include <memory>

using std::shared_ptr;
using std::cout;
using std::endl;
PPmarket::PPmarket(){}
PPmarket::~PPmarket(){}


shared_ptr<PowerPlantCards> const PPmarket::getPlant(int position) {
	if (position < 0 || position >= visiblePPlants.size()) return nullptr;
	return (visiblePPlants[position]);
}

bool PPmarket::DrawPlant() {
	shared_ptr<PowerPlantCards> PPlant = nullptr;

	while (visiblePPlants.size() < visibleCards && PPlants.size() > 0 && PPlant == nullptr) {
		shared_ptr<PowerPlantCards> top = PPlants[0];

		// Place card in the visible market
		visiblePPlants.push_back(top);

		PPlants.erase(PPlants.begin()); //shouldnt it be before pushback(top)

		// next line generates error
	//	std::sort(visiblePPlants.begin(), visiblePPlants.end(), [](shared_ptr<PowerPlantCards> pp1, std::shared_ptr<PowerPlantCards> pp2) { return  (pp1)->getCardValue() < (pp2)->getCardValue(); });
		return true;
	}
	return false;
}

// method to prints the visible PowerPlantCards
void PPmarket::printPPmarket(vector<shared_ptr<PowerPlantCards>> visiblePPlants)
{
	// Place the cards in the visible
	for (int i = 0; i < visibleCards && i < PPlants.size(); ++i) {
		visiblePPlants.push_back(PPlants[0]);
		PPlants.erase(PPlants.begin());
	}

	std::vector<shared_ptr<PowerPlantCards>>::iterator show; // create a vector iterator
	for (show = visiblePPlants.begin(); show != visiblePPlants.end(); ++show) {
		std::cout << *show << std::endl;
	}
}


void PPmarket::Setup() {
	// fill visiblePPlants vector
	for (int i = 0; i < visibleCards && i < PPlants.size(); ++i) {
		visiblePPlants.push_back(PPlants[0]);
		PPlants.erase(PPlants.begin());
	}
}

// print the visible PowerPlantCards
void PPmarket::printPPmarket() {
	cout << "PowerPlants on Auction: " << endl;
	for (int i = 0; i < futureMarketPosition; ++i)
		cout << "[" << i << "] " << *getPlant(i) << endl;

	cout << endl;

	cout << "Coming PowerPlants: " << endl;
	for (int i = futureMarketPosition; i < visibleCards; ++i)
		cout << "[" << i << "] " << *getPlant(i) << endl;
	cout << endl;
}



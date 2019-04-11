#include "PPMarketSingleton.h"
#include <algorithm>
#include <memory>
#include <random>

using std::shared_ptr;
using std::cout;
using std::endl;

//constructor
PPMarketSingleton::PPMarketSingleton()
{
	cout << "SingletonClass instance created!\n";
}

//destructor
PPMarketSingleton::~PPMarketSingleton()
{
}

 PPMarketSingleton* PPMarketSingleton::ppm_instance=0;

PPMarketSingleton* PPMarketSingleton::GetInstance() {

	if (!ppm_instance)
		ppm_instance = new PPMarketSingleton();
	return ppm_instance;

}

void PPMarketSingleton::ResetInstance()
{
	delete ppm_instance;
	ppm_instance = nullptr;
}

shared_ptr<PowerPlantCards> const PPMarketSingleton::getPlant(int position) {
	if (position < 0 || position >= visiblePPlants.size()) return nullptr;
	return (visiblePPlants[position]);
}

bool PPMarketSingleton::DrawPlant() {

	while (visiblePPlants.size() < visibleCards && PPlants.size() > 0) {
		shared_ptr<PowerPlantCards> top = PPlants[0];

		// Place Pplant card in the visible market
		visiblePPlants.push_back(top);

		PPlants.erase(PPlants.begin());

		// next line generates error
		std::sort(visiblePPlants.begin(), visiblePPlants.end(), [](shared_ptr<PowerPlantCards> pp1, std::shared_ptr<PowerPlantCards> pp2) { return  (pp1)->getCardValue() < (pp2)->getCardValue(); });

		return true;
	}
	return false;
}

// method to prints the visible PowerPlantCards
void PPMarketSingleton::printPPmarket(vector<shared_ptr<PowerPlantCards>> visiblePPlants)
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

void PPMarketSingleton::Setup() {
	// fill visiblePPlants vector
	for (int i = 0; i < visibleCards && i < PPlants.size(); ++i) {
		visiblePPlants.push_back(PPlants[0]);
		PPlants.erase(PPlants.begin());
	}

	// Shuffle deck of cards
	auto rng = std::default_random_engine{};
	std::shuffle(std::begin(PPlants), std::end(PPlants), rng);
}

// print the visible PowerPlantCards
void PPMarketSingleton::printPPmarket() {
	cout << "PowerPlants on Auction: " << endl;
	for (int i = 0; i < futureMarketPosition; ++i)
		cout << "[" << i << "] " << *getPlant(i) << endl;

	cout << endl;

	cout << "Coming PowerPlants: " << endl;
	for (int i = futureMarketPosition; i < visibleCards; ++i)
		cout << "[" << i << "] " << *getPlant(i) << endl;
	cout << endl;
}

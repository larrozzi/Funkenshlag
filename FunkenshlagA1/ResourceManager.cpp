#include "ResourceManager.h"
#include "Resource.h"

ResourceManager::ResourceManager() {

}
ResourceManager::ResourceManager(ResourceMarket rMarket) {
	//When creating a new Resource Manager, initialize each slot of the Resource Market
	//With empty array of Resources. These will be filled when the market is setup at
	//the beginning of the game.
	//Get each Slot of the ResourceMarket(which in turn has pointers to arrays of Resources.
	//The actual array is stored within the Resource Manager) and set the pointer in
	//the Resource Market to the array in the Resource Manager.
	//This basically links the pointers in the Market to the arrays in the 
	//Manager.
	for (int i = 0; i < rMarket.getMARKET_SIZE(); i++) {
		rMarket.getSlots()[i].setCoal(marketCoal[i]);
		rMarket.getSlots()[i].setOil(marketOil[i]);
		rMarket.getSlots()[i].setGarbage(marketGarbage[i]);
		rMarket.getSlots()[i].setUranium(marketUranium[i]);
	}
}

void ResourceManager::setupMarket(ResourceMarket rMarket){
	for (int i = 0; i < rMarket.getMARKET_SIZE - rMarket.getURANIUM_SLOTS; i++) {

	}
}

int ResourceManager::getNumOfCoal() {
	return numOfCoal;
}
int ResourceManager::getNumOfOil() {
	return numOfOil;
}
int ResourceManager::getNumOfGarbage() {
	return numOfGarbage;
}
int ResourceManager::getNumOfUranium() {
	return numOfUranium;
}

#include "ResourceManager.h"

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
	this->rMarket = rMarket;
	for (int i = 0; i < rMarket.getMARKET_SIZE(); i++) {
		rMarket.getSlots()[i].setCoal(marketCoal[i]);
		rMarket.getSlots()[i].setOil(marketOil[i]);
		rMarket.getSlots()[i].setGarbage(marketGarbage[i]);
		rMarket.getSlots()[i].setUranium(marketUranium[i]);
	}
}

void ResourceManager::setupMarket(){
	int oilStart = rMarket.getOIL_SLOT_START();
	int garbageStart = rMarket.getGARBAGE_SLOT_START();
	int uraniumStart = rMarket.getURANIUM_SLOT_START();
	int slotPrice = 0;
	//EACH SLOT
	for (int i = 0; i < rMarket.getMARKET_SIZE(); i++) {
		//EACH RESOURCE IN COAL ARRAY
		if (i < uraniumStart) {
			for (int k = 0; k < 3; k++) {
				rMarket.getSlots()[i].getSlotCoal()[k] = Resource(rMarket.getSlots()[i].getSlotPrice(), COAL);
			}
		}
		if (i < uraniumStart && i >= oilStart) {
			for (int k = 0; k < 3; k++) {
				rMarket.getSlots()[i].getSlotOil()[k] = Resource(rMarket.getSlots()[i].getSlotPrice(), OIL);
			}
		}
		if (i < uraniumStart && i >= garbageStart) {
			for (int k = 0; k < 3; k++) {
				rMarket.getSlots()[i].getSlotGarbage()[k] = Resource(rMarket.getSlots()[i].getSlotPrice(), GARBAGE);
			}
		}
		if (i >= uraniumStart) {
			for (int k = 0; k < 1; k++) {
				rMarket.getSlots()[i].getSlotUranium()[k] = Resource(rMarket.getSlots()[i].getSlotPrice(), URANIUM);
			}
		}
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

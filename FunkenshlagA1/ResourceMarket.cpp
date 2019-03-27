#include "ResourceMarket.h"
#include <iostream>
#include <cstring>


ResourceMarket::ResourceMarket(){

	for (int i = 0, j = 2; i < MARKET_SIZE; i++) {
		if (i < 8)
			//First 8 slots have different pricing than the
			slots[i] = Slot(i + 1);
		else {
			//last four
			slots[i] = Slot(i + j);
			j++;
		}
	}
	//For each slot in the market
	for (int i = 0; i < MARKET_SIZE; i++) {
		//If the slot is before the uranium slots
		if (i < URANIUM_SLOT_START) {
			for (int j = 0; j < 3; j++) {
				slots[i].setSlotCoal(new Resource(slots[i].getSlotPrice(), COAL), j);
				numOfCoal++;
			}
		}
		//if the slot is before the uranium and after oil price
		if (i < URANIUM_SLOT_START && i >= OIL_SLOT_START) {
			for (int j = 0; j < 3; j++) {
				slots[i].setSlotOil(new Resource(slots[i].getSlotPrice(), OIL), j);
				numOfOil++;
			}
		}
		//if the slot is before the uranium and after garbage price
		if (i < URANIUM_SLOT_START && i >= GARBAGE_SLOT_START) {
			for (int j = 0; j < 3; j++) {
				slots[i].setSlotGarbage(new Resource(slots[i].getSlotPrice(), GARBAGE), j);
				numOfGarbage++;
			}
		}
		//if the slot is after/at uranium price
		if (i >= URANIUM_SETUP) {
			for (int j = 0; j < 1; j++) {
				slots[i].setSlotUranium(new Resource(slots[i].getSlotPrice(), URANIUM), j);
				numOfUranium++;
			}
		}
	}
}

void ResourceMarket::bought(Type resource, int amount) {
	switch (resource) {
	case COAL: 

		break;
	case OIL: 
		break;
	case GARBAGE: 
		break;
	case URANIUM: 
		break;
	}
}
int ResourceMarket::getMARKET_SIZE() const
{
	return MARKET_SIZE;
} 
int ResourceMarket::getOIL_SLOT_START() const
{
	return OIL_SLOT_START;
}
int ResourceMarket::getGARBAGE_SLOT_START() const
{
	return GARBAGE_SLOT_START;
}
int ResourceMarket::getURANIUM_SLOT_START() const
{
	return URANIUM_SLOT_START;
}

const int ResourceMarket::getFirstEmptyCoal() {
	return ((MARKET_SIZE - numOfCoal) - 1);
}
const int ResourceMarket::getFirstEmptyOil() {
	((MARKET_SIZE - numOfOil) - 1);
}
const int ResourceMarket::getFirstEmptyGarbage() {
	((MARKET_SIZE - numOfGarbage) - 1);
}
const int ResourceMarket::getFirstEmptyUranium() {
	((MARKET_SIZE - numOfUranium) - 1);
}

ResourceMarket::Slot* ResourceMarket::getSlots() {
	return slots;
}

const ResourceMarket::Slot* ResourceMarket::getSlots() const{
	return slots;
}

int ResourceMarket::getNumOfCoal() const {
	return numOfCoal;
}
int ResourceMarket::getNumOfOil() const {
	return numOfOil;
}
int ResourceMarket::getNumOfGarbage() const {
	return numOfGarbage;
}
int ResourceMarket::getNumOfUranium() const {
	return numOfUranium;
}


//SLOT METHODS
ResourceMarket::Slot::Slot(){
}

ResourceMarket::Slot::Slot(int price){
	this->price = price;
}

int ResourceMarket::Slot::getSlotPrice() const{
	return price;
}

void ResourceMarket::Slot::setPrice(const int price){
	this->price = price;
}

Resource* ResourceMarket::Slot::getSlotCoal() {
	return slotCoal;
}
const Resource* ResourceMarket::Slot::getSlotCoal() const {
	return slotCoal;
}
Resource* ResourceMarket::Slot::getSlotOil() {
	return slotOil;
}
const Resource* ResourceMarket::Slot::getSlotOil() const {
	return slotOil;
}
Resource* ResourceMarket::Slot::getSlotGarbage() {
	return slotGarbage;
}
const Resource* ResourceMarket::Slot::getSlotGarbage() const {
	return slotGarbage;
}
Resource* ResourceMarket::Slot::getSlotUranium() {
	return slotUranium;
}
const Resource* ResourceMarket::Slot::getSlotUranium() const{
	return slotUranium;
}

void ResourceMarket::Slot::setSlotCoal(Resource* coal,int index) {
	if (coal->getType() != COAL) {
		return;
	}
	else {
		slotCoal[index] = *coal;
	}
}
void ResourceMarket::Slot::setSlotOil(Resource* oil,int index) {
	if (oil->getType() != OIL) {
		return;
	}
	else {
		slotOil[index] = *oil;
	}

}
void ResourceMarket::Slot::setSlotGarbage(Resource* garbage,int index) {
	if (garbage->getType() != GARBAGE) {
		return;
	}
	else {
		slotGarbage[index] = *garbage;
	}
}
void ResourceMarket::Slot::setSlotUranium(Resource* uranium,int index) {
	if (uranium->getType() != URANIUM) {
		return;
	}
	else {
		slotUranium[index] = *uranium;
	}
}
std::ostream& operator<<(std::ostream& out, const ResourceMarket& market) {
	for (int i = 0; i < market.MARKET_SIZE; i++) {
		out << "SLOT " << i + 1 << std::endl;
		if (i < market.URANIUM_SLOT_START) {
			for (int j = 0; j < 3; j++) {
				out << market.getSlots()[i].getSlotCoal()[j] << std::endl;
			}
			for (int j = 0; j < 3; j++) {
				out << market.slots[i].getSlotOil()[j] << std::endl;
			}
			for (int j = 0; j < 3; j++) {
				out << market.getSlots()[i].getSlotGarbage()[j] << std::endl;
			}
			out << market.getSlots()[i].getSlotUranium()[0] << std::endl;
		}
		else {
			out << market.getSlots()[i].getSlotUranium()[0] << std::endl;
		}
		out << std::endl;
	}
	return out;
}



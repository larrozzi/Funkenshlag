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
				Resource::decreCoalInStock();
				numOfCoal++;
			}
		}
		//if the slot is before the uranium and after oil price
		if (i < URANIUM_SLOT_START && i >= OIL_SLOT_START) {
			for (int j = 0; j < 3; j++) {
				slots[i].setSlotOil(new Resource(slots[i].getSlotPrice(), OIL), j);
				Resource::decreOilInStock();
				numOfOil++;
			}
		}
		//if the slot is before the uranium and after garbage price
		if (i < URANIUM_SLOT_START && i >= GARBAGE_SLOT_START) {
			for (int j = 0; j < 3; j++) {
				slots[i].setSlotGarbage(new Resource(slots[i].getSlotPrice(), GARBAGE), j);
				Resource::decreGarbageInStock();
				numOfGarbage++;
			}
		}
		//if the slot is after/at uranium price
		if (i >= URANIUM_SETUP) {
			for (int j = 0; j < 1; j++) {
				slots[i].setSlotUranium(new Resource(slots[i].getSlotPrice(), URANIUM), j);
				Resource::decreUraniumInStock();
				numOfUranium++;
			}
		}
	}
}

bool ResourceMarket::bought(Type type, int amount) {
	
	int removed = 0;

	if (type == COAL) {
		if (amount > numOfCoal)
			return false;
		for (int i = 0; i < MARKET_SIZE; i++) {
			if (removed == amount) {
				return true;
			}
			for (int j = 0; j < 3; j++) {
				if (removed == amount)
					return true;
				if (slots[i].getSlotCoal()[j].getType() != COAL)
					continue;
				slots[i].setSlotCoal(new Resource(0, NONE), j);
				removed++;
			}
			currentEmptyCoalSlot++;
		}
		numOfCoal -= amount;
		return true;
	}
	else if (type == OIL) {
		if (amount > numOfOil)
			return false;
		for (int i = 0; i < MARKET_SIZE; i++) {
			if (removed == amount) {
				return true;
			}
			for (int j = 0; j < 3; j++) {
				if (removed == amount)
					return true;
				if (slots[i].getSlotOil()[j].getType() != OIL)
					continue;
				slots[i].setSlotOil(new Resource(0, NONE), j);
				removed++;
			}
			currentEmptyOilSlot++;
		}
		numOfOil -= amount;
		return true;
	}
	else if (type == GARBAGE) {
		if (amount > numOfGarbage)
			return false;
		for (int i = 0; i < MARKET_SIZE; i++) {
			if (removed == amount) {
				return true;
			}
			for (int j = 0; j < 3; j++) {
				if (removed == amount)
					return true;
				if (slots[i].getSlotGarbage()[j].getType() != GARBAGE)
					continue;
				slots[i].setSlotGarbage(new Resource(0, NONE), j);
				removed++;
			}
			currentEmptyGarbageSlot++;
		}
		numOfGarbage -= amount;
		return true;

	}
	else if (type == URANIUM) {
		if (amount > numOfUranium)
			return false;
		for (int i = 0; i < MARKET_SIZE; i++) {
			if (removed == amount) {
				return true;
			}
			for (int j = 0; j < 1; j++) {
				if (removed == amount)
					return true;
				if (slots[i].getSlotUranium()[j].getType() != URANIUM)
					continue;
				slots[i].setSlotUranium(new Resource(0, NONE), j);
				removed++;
			}
			currentEmptyUraniumSlot++;
		}
		numOfUranium -= amount;
		return true;
	}
    return true;
}

void ResourceMarket::resupply(int step, int numOfPlayers) {
	int refillCoal = 0;
	int refillOil = 0;
	int refillGarbage = 0;
	int refillUranium = 0;
	int i = 0;
	switch (numOfPlayers) {
	case 2:
		switch (step) {
		case 1:
			refillCoal = 3;
			refillOil = 2;
			refillGarbage = 1;
			refillUranium = 1;
			//while (i < refillCoal || Resource::getCoalInStock() >= i)
				for (; i < refillCoal; i++) {
					if (Resource::getCoalInStock() == 0) {
						break;
					}
					slots[getCurrentEmptyCoalSlot()].setSlotCoal(new Resource(slots[getCurrentEmptyCoalSlot()].getSlotPrice(), COAL), getEmptySpotInSlot(COAL));
					Resource::decreCoalInStock();
					if (getEmptySpotInSlot(COAL) == -1) {
						currentEmptyCoalSlot--;
					}
				}
		case 2:
			refillCoal = 4;
			refillOil = 2;
			refillGarbage = 2;
			refillUranium = 1;
		case 3:
			refillCoal = 3;
			refillOil = 4;
			refillGarbage = 3;
			refillUranium = 1;
		}
	case 3:
		switch (step) {
		case 1:
			refillCoal = 4;
			refillOil = 2;
			refillGarbage = 1;
			refillUranium = 1;

		case 2:
			refillCoal = 5;
			refillOil = 3;
			refillGarbage = 2;
			refillUranium = 1;
		case 3:
			refillCoal = 3;
			refillOil = 4;
			refillGarbage = 3;
			refillUranium = 1;
		}
	case 4:
		switch (step) {
		case 1:
			refillCoal = 5;
			refillOil = 3;
			refillGarbage = 2;
			refillUranium = 1;
		case 2:
			refillCoal = 6;
			refillOil = 4;
			refillGarbage = 3;
			refillUranium = 2;
		case 3:
			refillCoal = 4;
			refillOil = 5;
			refillGarbage = 4;
			refillUranium = 2;
		}
	case 5:
		switch (step) {
		case 1:
			refillCoal = 5;
			refillOil = 4;
			refillGarbage = 3;
			refillUranium = 2;
		case 2:
			refillCoal = 7;
			refillOil = 5;
			refillGarbage = 3;
			refillUranium = 3;
		case 3:
			refillCoal = 5;
			refillOil = 6;
			refillGarbage = 5;
			refillUranium = 2;
		}
	case 6:
		switch (step) {
		case 1:
			refillCoal = 7;
			refillOil = 5;
			refillGarbage = 3;
			refillUranium = 2;
		case 2:
			refillCoal = 9;
			refillOil = 6;
			refillGarbage = 5;
			refillUranium = 3;
		case 3:
			refillCoal = 6;
			refillOil = 7;
			refillGarbage = 6;
			refillUranium = 3;
		}
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
int ResourceMarket::getCurrentEmptyCoalSlot() {
	return currentEmptyCoalSlot;
}
int ResourceMarket::getCurrentEmptyOilSlot() {
	return currentEmptyOilSlot;
}
int ResourceMarket::getCurrentEmptyGarbageSlot() {
	return currentEmptyGarbageSlot;
}
int ResourceMarket::getCurrentEmptyUraniumSlot() {
	return currentEmptyUraniumSlot;
}

int ResourceMarket::getEmptySpotInSlot(Type resource) {
	int i = 0;
	switch (resource) {
	case COAL:
		for (; i < 3; i++) {
			if (this->slots[this->getCurrentEmptyCoalSlot()].getSlotCoal()[i].getType() != NONE) {
				break;
			}
		}
		return (i - 1);
	case OIL:
		for (; i < 3; i++) {
			if (this->slots[this->getCurrentEmptyOilSlot()].getSlotOil()[i].getType() != NONE) {
				break;
			}
		}
		return (i - 1);

	case GARBAGE:
		for (; i < 3; i++) {
			if (this->slots[this->getCurrentEmptyGarbageSlot()].getSlotGarbage()[i].getType() != NONE) {
				break;
			}
		}
		return (i - 1);
	case URANIUM:
		return (i);
	}
    return 0;
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
	slotCoal[index] = *coal;
}
void ResourceMarket::Slot::setSlotOil(Resource* oil,int index) {
	slotOil[index] = *oil;

}
void ResourceMarket::Slot::setSlotGarbage(Resource* garbage,int index) {
	slotGarbage[index] = *garbage;
}
void ResourceMarket::Slot::setSlotUranium(Resource* uranium,int index) {
	slotUranium[index] = *uranium;
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



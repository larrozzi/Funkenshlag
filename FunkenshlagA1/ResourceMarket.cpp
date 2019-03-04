#include "ResourceMarket.h"
#include <iostream>
#include <cstring>

ResourceMarket::ResourceMarket() {

}

ResourceMarket::ResourceMarket(Resource* coal, Resource* oil, Resource* garbage,Resource* uranium){

	for (int i = 0, j = 2; i < MARKET_SIZE; i++) {
		if (i < 8)
			//First 8 slots have different pricing than the
			slots[i] = Slot(i + 1, coal, oil, garbage, uranium);
		else {
			//last four
			slots[i] = Slot(i + j, coal, oil, garbage, uranium);
			j++;
		}

	}
}

int ResourceMarket::getMARKET_SIZE()
{
	return MARKET_SIZE;
}
int ResourceMarket::getOIL_SLOT_START()
{
	return OIL_SLOT_START;
}
int ResourceMarket::getGARBAGE_SLOT_START()
{
	return GARBAGE_SLOT_START;
}
int ResourceMarket::getURANIUM_SLOT_START()
{
	return URANIUM_SLOT_START;
}

ResourceMarket::Slot* ResourceMarket::getSlots(){
	return slots;
}

//SLOT METHODS
ResourceMarket::Slot::Slot(){
}

ResourceMarket::Slot::Slot(int price, Resource coal[], Resource oil[], Resource garbage[], Resource uranium[]){
	this->price = price;
	this->slotCoal = coal;
	this->slotOil = oil;
	this->slotGarbage = garbage;
	this->slotUranium = uranium;
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
Resource* ResourceMarket::Slot::getSlotOil() {
	return slotOil;
}
Resource* ResourceMarket::Slot::getSlotGarbage() {
	return slotGarbage;
}
Resource* ResourceMarket::Slot::getSlotUranium() {
	return slotUranium;
}
void ResourceMarket::Slot::setCoal(Resource* coal) {
	this->slotCoal = coal;
}
void ResourceMarket::Slot::setOil(Resource* oil) {
	this->slotOil = oil;
}
void ResourceMarket::Slot::setGarbage(Resource* garbage) {
	this->slotGarbage = garbage;
}
void ResourceMarket::Slot::setUranium(Resource* uranium) {
	this->slotUranium = uranium;
}
#include "ResourceMarket.h"
#include <iostream>
#include <cstring>

ResourceMarket::ResourceMarket() {

}
ResourceMarket::ResourceMarket(Resource* coal, Resource* oil, Resource* garbage,Resource* uranium){

	for (int i = 0, j = 2; i < MARKET_SIZE; i++) {
		if (i < 8)
			//First 8 slots have different pricing than the
			slots[i] = new Slot(i + 1, coal, oil, garbage, uranium);
		else {
			//last four
			slots[i] = new Slot(i + j, coal, oil, garbage, uranium);
			j++;
		}

	}
}

//SLOT METHODS
ResourceMarket::Slot::Slot(){
}

ResourceMarket::Slot::Slot(int price, Resource coal[], Resource oil[], Resource garbage[], Resource uranium[]){
	this->price = price;
	this->coal = coal;
	this->oil = oil;
	this->garbage = garbage;
	this->uranium = uranium;
}

int ResourceMarket::Slot::getPrice() const{
	return 0;
}

void ResourceMarket::Slot::setPrice(const int price){

}

Resource* ResourceMarket::Slot::getCoal() {
	return coal;
}
Resource* ResourceMarket::Slot::getOil() {
	return oil;
}
Resource* ResourceMarket::Slot::getGarbage() {
	return garbage;
}
Resource* ResourceMarket::Slot::getUranium() {
	return uranium;
}
void ResourceMarket::Slot::setCoal(Resource* coal) {
	this->coal = coal;
}
void ResourceMarket::Slot::setOil(Resource* oil) {
	this->oil = oil;
}
void ResourceMarket::Slot::setGarbage(Resource* garbage) {
	this->garbage = garbage;
}
void ResourceMarket::Slot::setUranium(Resource* uranium) {
	this->uranium = uranium;
}
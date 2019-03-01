#include "ResourceMarket.h"

ResourceMarket::ResourceMarket() {

	for (int i = 0; i < MARKET_SIZE; i++) {
		slots[i] = Slot(i + 3);
	}
}
//SLOT METHODS
ResourceMarket::Slot::Slot() {
}

ResourceMarket::Slot::Slot(int price) {
}

int ResourceMarket::Slot::getPrice() {
	return 0;
}

void ResourceMarket::Slot::setPrice(int price) {

}
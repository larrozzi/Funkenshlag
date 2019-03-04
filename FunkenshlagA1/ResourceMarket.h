#pragma once
#include "Resource.h"

class ResourceMarket{
private:
	class Slot {
	private:
		int price;
		Resource* slotCoal;
		Resource* slotOil;
		Resource* slotGarbage;
		Resource* slotUranium;
	public:
		Slot();
		Slot(int price, Resource coal[], Resource oil[], Resource garbage[], Resource uranium[]);
		Slot(int price, Resource uranium[]);
		int getPrice() const;
		void setPrice(const int price);
		Resource* getSlotCoal();
		Resource* getSlotOil();
		Resource* getSlotGarbage();
		Resource* getSlotUranium();
		void setCoal(Resource* coal);
		void setOil(Resource* oil);
		void setGarbage(Resource* garbage);
		void setUranium(Resource* uranium);
	};
	static const int MARKET_SIZE = 12;
	static const int URANIUM_SLOTS = 4;
	Slot slots[MARKET_SIZE];
public:
	ResourceMarket();
	int getMARKET_SIZE();
	int getURANIUM_SLOTS();
	Slot* getSlots();
	ResourceMarket(Resource* coal, Resource* oil, Resource* garbage, Resource* uranium);


};
#pragma once
#include "Resource.h"

class ResourceMarket{
private:
	class Slot {
	private:
		int price;
		//Arrays of resources in the Slot
		/*  EXAMPLE
			SLOT #8
			
			[C C C]
			[O O O] [U]
			[G  G  G] 
		*/
		Resource* slotCoal;
		Resource* slotOil;
		Resource* slotGarbage;
		Resource* slotUranium;
	public:

		//SLOT constructors
		Slot();
		Slot(int price);

		//SLOT getters
		int getSlotPrice() const;
		Resource* getSlotCoal();
		Resource* getSlotOil();
		Resource* getSlotGarbage();
		Resource* getSlotUranium();

		//SLOT setters
		void setPrice(const int price);
		void setCoal(Resource* coal);
		void setOil(Resource* oil);
		void setGarbage(Resource* garbage);
		void setUranium(Resource* uranium);
	};

	//MARKET const variables
	static const int MARKET_SIZE = 12;
	static const int OIL_SLOT_START = 2;
	static const int GARBAGE_SLOT_START = 6;
	static const int URANIUM_SLOT_START = 8;

	//Array of slots in Market
	Slot slots[MARKET_SIZE];
public:
	ResourceMarket();
	int getMARKET_SIZE();
	int getOIL_SLOT_START();
	int getGARBAGE_SLOT_START();
	int getURANIUM_SLOT_START();
	Slot* getSlots();


};
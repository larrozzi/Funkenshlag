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
		Resource slotCoal[3];
		Resource slotOil[3];
		Resource slotGarbage[3];
		Resource slotUranium[1];
	public:

		//SLOT constructors
		Slot();
		Slot(int price);

		//SLOT getters
		int getSlotPrice() const;
		Resource* getSlotCoal();
		const Resource* getSlotCoal() const;
		Resource* getSlotOil();
		const Resource* getSlotOil() const;
		Resource* getSlotGarbage();
		const Resource* getSlotGarbage() const;
		Resource* getSlotUranium();
		const Resource* getSlotUranium() const;

		//SLOT setters
		void setPrice(const int price);
		void setSlotCoal(Resource* coal, int index);
		void setSlotOil(Resource* oil, int index);
		void setSlotGarbage(Resource* garbage, int index);
		void setSlotUranium(Resource* uranium, int index);

	};

	//MARKET const variables
	static const int MARKET_SIZE = 12;
	static const int OIL_SLOT_START = 2;
	static const int GARBAGE_SLOT_START = 6;
	static const int URANIUM_SLOT_START = 8;
	static const int URANIUM_SETUP = 10;

	//Current number of the resource left available in stock.
	int numOfCoal = 0;
	int numOfOil = 0;
	int numOfGarbage = 0;
	int numOfUranium = 0;
	
	//Next Empty Slot in the market
	int currentEmptyCoalSlot = -1;
	int currentEmptyOilSlot = 1;
	int currentEmptyGarbageSlot = 5;
	int currentEmptyUraniumSlot = 9;

	//Array of slots in Market
	Slot slots[MARKET_SIZE];
public:
	ResourceMarket();
	int getMARKET_SIZE() const;
	int getOIL_SLOT_START() const;
	int getGARBAGE_SLOT_START() const;
	int getURANIUM_SLOT_START() const;
	int getNumOfCoal() const;
	int getNumOfOil() const;
	int getNumOfGarbage() const;
	int getNumOfUranium() const;
	int getCurrentEmptyCoalSlot();
	int getCurrentEmptyOilSlot();
	int getCurrentEmptyGarbageSlot();
	int getCurrentEmptyUraniumSlot();
	int getEmptySpotInSlot(Type resource);
	Slot* getSlots();
	const Slot* getSlots() const;

	bool bought(Type,int);
	void resupply(int step, int numOfPlayers);
	friend std::ostream& operator<<(std::ostream& outs, const ResourceMarket& market);
};
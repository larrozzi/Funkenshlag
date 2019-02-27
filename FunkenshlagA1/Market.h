#pragma once

#include "Slot.h"

template <class T>
class Market {
private:
	int numOfSlots;
	Slot slots[numOfSlots];
public:
	Market();
	class Slot {
	private:
		T positions[];
		int price;
	public:
		Slot();
		Slots(int numOfSlots);
	};

};

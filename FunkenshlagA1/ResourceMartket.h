#pragma once
#include "Resource.h"

class ResourceMarket{
private:
	class Slot{
	private:
		int price;
		Resource coal[3];
		Resource oil[3];
		Resource garbage[3];
		Resource uranium[1];
	public:
		Slot();
		Slot(int price,Resource coal[], Resource oil[], Resource garbage[], Resource uranium[]);
		int getPrice();
		void setPrice(int price);
	};
	static const int MARKET_SIZE = 12;
	Slot slots[MARKET_SIZE];
public:
	ResourceMarket();
};
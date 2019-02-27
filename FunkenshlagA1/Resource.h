#pragma once

class Resource{
    //Type of the resource
    enum Type { NONE, COAL, OIL, HYBRID, GARBAGE, URANIUM };
private:
	int price;
	Type type;
public:
	Resource();
	Resource(int price, Type type);
	int inline getPrice();
	void setPrice(int price);
};

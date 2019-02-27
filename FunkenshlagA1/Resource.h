#pragma once

//Type of the resource
enum Type { NONE, COAL, OIL, HYBRID, GARBAGE, URANIUM };

class Resource{
private:
	int price;
	Type type;
public:
	Resource();
	Resource(int price, Type type);
	int inline getPrice();
	void setPrice(int price);
};

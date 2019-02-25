#pragma once

class Resource{
private:
	int price;
	//Type of the resource
	enum Type { NONE, COAL, OIL, GARBAGE, URANIUM };
	Type type;
public:
	Resource();
	Resource(int price, Type type);
	int inline getPrice();
	void setPrice(int price);
};
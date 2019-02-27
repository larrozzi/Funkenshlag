#pragma once

class Resource{
public:
	enum Type { NONE, COAL, OIL, GARBAGE, URANIUM };
	Resource();
	Resource(int price, Type type);
	inline Type getType();
	void setType(Type type);
	inline int getPrice();
	void setPrice(int price);
private:
	int price;
	//Type of the resource
	Type type;
};
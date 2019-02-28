#pragma once

class Resource{
public:
	//Possible type for the resource
	enum Type { NONE, COAL, OIL, GARBAGE, URANIUM };
	//default constructor
	Resource();
	Resource(int price, Type type);
	inline Type getType() const;
	void setType(Type type);
	inline int getPrice() const;
	void setPrice(int price);
private:
	//price of the resource
	int price;
	//Type of the resource
	Type type;
};
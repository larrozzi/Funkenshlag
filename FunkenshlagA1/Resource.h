#pragma once
#include <iostream>
#include <string>

//Type of the resource
enum Type { NONE, COAL, OIL, HYBRID, GARBAGE, URANIUM, ECOFUSION };

class Resource {
private:
	int price;
	Type type;
public:
	Resource();
	Resource(int price, Type type);

	//getters
	Type getType() const;
	int getPrice() const;

	//setters
	void setPrice(int price);
	void setType(Type type);

	std::string printType(Type resource) const;
	friend std::ostream& operator<<(std::ostream& outs, const Resource& resource);

};
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
	Type getType() const;
	void setType(Type type);
	inline int getPrice() const;
	void setPrice(int price);

	std::string printType(Type resource) const;
	friend std::ostream& operator<<(std::ostream& outs, const Resource& resource);

};
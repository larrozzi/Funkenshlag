#pragma once
#include <iostream>
#include <string>

//Type of the resource
enum Type { NONE, COAL, OIL, HYBRID, GARBAGE, URANIUM, ECOFUSION };

class Resource {
private:
	int price;
	Type type;
	const static int MAX_COAL = 24;
	const static int MAX_OIL = 24;
	const static int MAX_GARBAGE = 24;
	const static int MAX_URANIUM = 12;
public:
	Resource();
	Resource(int price, Type type);

	//getters
	Type getType() const;
	int getPrice() const;
	const int getMAX_COAL();
	const int getMAX_OIL();
	const int getMAX_GARBAGE();
	const int getMAX_URANIUM();

	//setters
	void setPrice(int price);
	void setType(Type type);

	std::string printType() const;
	friend std::ostream& operator<<(std::ostream& outs, const Resource& resource);

};
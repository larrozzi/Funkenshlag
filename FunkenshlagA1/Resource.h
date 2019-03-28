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
	static int coalInStock;
	static int oilInStock;
	static int garbageInStock;
	static int uraniumInStock;
public:
	Resource();
	Resource(int price, Type type);

	//getters
	Type getType() const;
	int getPrice() const;
	static const int getMAX_COAL();
	static const int getMAX_OIL();
	static const int getMAX_GARBAGE();
	static const int getMAX_URANIUM();
	static int getCoalInStock();
	static int getOilInStock();
	static int getGarbageInStock();
	static int getUraniumInStock();

	//setters
	void setPrice(int price);
	void setType(Type type);
	static void decreCoalInStock();
	static void decreOilInStock();
	static void decreGarbageInStock();
	static void decreUraniumInStock();

	std::string printType() const;
	friend std::ostream& operator<<(std::ostream& outs, const Resource& resource);

};
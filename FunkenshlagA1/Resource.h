#pragma once

//Type of the resource
enum Type { NONE, COAL, OIL, HYBRID, GARBAGE, URANIUM };

class Resource {
private:
	int price;
	Type type;
public:
    Resource();
    Resource(int price, Type type);
	inline Type getType() const;
	void setType(Type type);
	inline int getPrice() const;
    void setPrice(int price);
};

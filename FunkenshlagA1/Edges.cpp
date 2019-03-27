//
//  Edges.cpp
//  FunkenshlagA1
//
//  Created by Alek Faruq Aliu on 2019-03-25.
//  Copyright © 2019 Adelekan Faruq Aliu. All rights reserved.
//

#include "Edges.h"
using std::shared_ptr;

Edges::Edges() {}
Edges::Edges(shared_ptr<CityNode> firstCity, shared_ptr<CityNode> secCity, int cost) : first(firstCity), sec(secCity), cost(cost) {}
Edges::~Edges() {}

// getters
int Edges::getCost() const { return cost; }
shared_ptr<CityNode> Edges::getFirst() const { return first; }
shared_ptr<CityNode> Edges::getSec() const { return sec; }

// setters
void Edges::setCost(int cost) { this->cost = cost; }
//shared_ptr<CityNode> Edges::setFirst(shared_ptr<CityNode> fCity) { this->first = fCity; }
//shared_ptr<CityNode> Edges::setSec(shared_ptr<CityNode> sCity) { this->sec = sCity; }

// operator assignment overloading
bool Edges::operator==(const Edges& e) const {
    return ((this->first == e.first && this->sec == e.sec) ||
            (this->sec == e.first && this->first == e.sec)) &&
             this->cost == e.cost;
}
// friends
bool operator==(const shared_ptr<Edges>& first, const shared_ptr<Edges>& sec) {
    return ((first->first == sec->first && first->sec == sec->sec) ||
            (first->sec == sec->first && first->first == sec->sec)) &&
             first->cost == sec->cost;
}

bool operator==(const shared_ptr<Edges>& first, const Edges& sec) {
    return ((first->first == sec.first && first->sec == sec.sec) ||
            (first->sec == sec.first && first->first == sec.sec)) &&
             first->cost == sec.cost;
}

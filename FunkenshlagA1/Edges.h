//
//  Edges.h
//  FunkenshlagA1
//
//  Created by Alek Faruq Aliu on 2019-03-25.
//  Copyright © 2019 Adelekan Faruq Aliu. All rights reserved.
//

# pragma once
#include <stdio.h>
#include <memory>
#include "CityNode.h"

using std::shared_ptr;

class Edges
{
private:
    shared_ptr<CityNode> first;
    shared_ptr<CityNode> sec;
    int cost = 0;
    
public:
    Edges();
    Edges(shared_ptr<CityNode> firstCity, shared_ptr<CityNode> secCity, int cost);
    ~Edges();
    
    // getters
    int getCost() const;
    shared_ptr<CityNode> getFirst() const;
    shared_ptr<CityNode> getSec() const;
    
    // setters
    void setCost(int cost);
    shared_ptr<CityNode> setFirst(shared_ptr<CityNode> fCity);
    shared_ptr<CityNode> setSec(shared_ptr<CityNode> sCity);

    // operator
    bool operator==(const Edges& e) const;
    friend bool operator==(const shared_ptr<Edges>& first, const shared_ptr<Edges>& sec);
    friend bool operator==(const shared_ptr<Edges>& first, const Edges& sec);
};

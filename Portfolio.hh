#pragma once

#include <vector>
#include <iostream>
#include "Deal.hh"

class Portfolio
{
private:
    std::vector<Deal> deals;

public:
    void addDeal(Deal d);
    double calculateTotalInterest() const;
    void print() const;
    const std::vector<Deal> &getDeals() const;
};
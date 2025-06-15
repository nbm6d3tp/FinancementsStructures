#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Portfolio.hh"
using namespace std;
#include "Deal.hh"

class Lender
{
private:
    string name;
    Portfolio portfolio;

public:
    explicit Lender(const string n) : name(n) {}
    void print() const
    {
        cout << "Lender: " << name << endl;
        portfolio.print();
    }
    const string getName() const
    {
        return name;
    }
    void addDeal(Deal d)
    {
        portfolio.addDeal(d);
    }
    Portfolio getPortfolio() const
    {
        return portfolio;
    }
};
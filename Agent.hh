#pragma once
#include <iostream>
#include <string>
#include "Lender.hh"
using namespace std;

class Agent
{
private:
    // Lender is a forward declaration, so we can use pointers to it
    Lender *lender;

public:
    explicit Agent(Lender *l) : lender(l) {}
    void print() const
    {
        cout << "Agent for Lender: " << lender->getName() << endl;
    }
    const string getName() const
    {
        return lender->getName();
    }
};
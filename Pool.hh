#pragma once
#include <iostream>
#include <string>
#include "Lender.hh"
using namespace std;

class Pool
{
private:
    Lender *lender;

public:
    explicit Pool(Lender *l) : lender(l) {}
    void print() const
    {
        cout << "Pool for Lender: " << lender->getName() << endl;
    }
    const string getName() const
    {
        return lender->getName();
    }
};
#pragma once
#include <iostream>
#include <string>
using namespace std;

class Borrower
{
private:
    string name;

public:
    Borrower(const string n) : name(n) {}
    void print() const
    {
        cout << "Borrower: " << name << endl;
    }
    const string getName() const
    {
        return name;
    }
};
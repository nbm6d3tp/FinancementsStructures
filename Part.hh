#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Part
{
private:
    string payDate;
    double amount;

public:
    Part(const string d, double a) : payDate(d), amount(a) {}
    void print() const
    {
        cout << "Part paid on " << payDate << " for amount: " << amount << endl;
    }
    const string getPayDate() const
    {
        return payDate;
    }
    double getAmount() const
    {
        return amount;
    }
};
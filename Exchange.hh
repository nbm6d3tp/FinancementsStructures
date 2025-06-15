#pragma once
#include <string>
#include <iostream>
#include "Currency.hh"
using namespace std;

class Exchange
{
private:
    Currency from; // Currency to exchange from
    Currency to;   // Currency to exchange to
    double rate;   // Exchange rate from 'from' to 'to'
public:
    Exchange(Currency f, Currency t, double r)
        : from(f), to(t), rate(r) {}

    // Function to convert an amount from 'from' currency to 'to' currency
    double convert(double amount) const
    {
        return amount * rate;
    }
    Currency getFromCurrency() const
    {
        return from;
    }
    Currency getToCurrency() const
    {
        return to;
    }
    double getRate() const
    {
        return rate;
    }
};
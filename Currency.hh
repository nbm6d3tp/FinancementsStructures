#pragma once
#include <string>
using namespace std;

enum Currency
{
    EUR, // Euro
    USD, // US Dollar
    GBP, // British Pound
    JPY, // Japanese Yen
    CHF, // Swiss Franc
    AUD, // Australian Dollar
    CAD, // Canadian Dollar
    CNY  // Chinese Yuan
};

string currencyToString(Currency cur)
{
    switch (cur)
    {
    case EUR:
        return "EUR";
    case USD:
        return "USD";
    case GBP:
        return "GBP";
    case JPY:
        return "JPY";
    case CHF:
        return "CHF";
    case AUD:
        return "AUD";
    case CAD:
        return "CAD";
    case CNY:
        return "CNY";
    default:
        return "Unknown Currency";
    }
}
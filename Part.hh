#pragma once

#include <string>
#include <iostream>
#include <iomanip>

class Part
{
private:
    std::string payDate;
    double amount;

public:
    Part(const std::string &d, double a);
    void print(int levelIndent) const;
    const std::string getPayDate() const;
    double getAmount() const;
};
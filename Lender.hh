#pragma once

#include <string>

class Lender
{
private:
    std::string name;

public:
    explicit Lender(const std::string n);
    void print() const;
    const std::string getName() const;
};
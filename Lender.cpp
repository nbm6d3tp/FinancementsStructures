#include "Lender.hh"
#include <iostream>

Lender::Lender(const std::string n) : name(n) {}

void Lender::print() const
{
    std::cout << "Lender: " << name << std::endl;
}

const std::string Lender::getName() const
{
    return name;
}
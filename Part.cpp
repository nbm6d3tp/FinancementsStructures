#include "Part.hh"
Part::Part(const std::string &d, double a) : payDate(d), amount(a) {}

void Part::print(int levelIndent) const
{
    std::cout << std::string(levelIndent, ' ') << "Part paid on " << payDate
              << ", Amount: " << std::fixed << std::setprecision(2) << amount << std::endl;
}

const std::string Part::getPayDate() const
{
    return payDate;
}

double Part::getAmount() const
{
    return amount;
}

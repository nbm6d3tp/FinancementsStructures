#include "Portfolio.hh"

void Portfolio::addDeal(Deal d)
{
    deals.push_back(d);
}

double Portfolio::calculateTotalInterest() const
{
    double totalInterest = 0.0;
    for (const Deal &deal : deals)
    {
        totalInterest += deal.calculateTotalInterest();
    }
    return totalInterest;
}

void Portfolio::print() const
{
    std::cout << "Portfolio contains " << deals.size() << " deals." << std::endl;
    for (const Deal &deal : deals)
    {
        deal.print();
    }
}

const std::vector<Deal> &Portfolio::getDeals() const
{
    return deals;
}

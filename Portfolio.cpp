#include "Portfolio.hh"
#include "Deal.hh"
#include "Lender.hh"

Portfolio::Portfolio(Currency cur) : currency(cur) {}

void Portfolio::setLender(Lender *l)
{
    lender = l;
}
void Portfolio::addDeal(Deal *d)
{
    if (d == nullptr)
    {
        throw std::runtime_error("Cannot add a null deal to the portfolio.");
    }
    deals.push_back(d);
}

double Portfolio::calculateTotalInterest() const
{
    double totalInterest = 0.0;
    if (deals.empty())
    {
        return totalInterest; // Return 0 if there are no deals
    }
    for (Deal *deal : deals)
    {
        for (const Facility &facility : deal->getFacilities())
        {
            std::vector<Lender *> lenders = facility.getLenders();
            auto it = std::find(lenders.begin(), lenders.end(), lender);
            if (it != lenders.end())
            {
                totalInterest += exchange(facility.calculateInterest() / lenders.size(), facility.getCurrency(), currency);
            }
        }
    }
    return totalInterest;
}

double Portfolio::calculateTotalOriginalValue() const
{
    double totalValue = 0.0;
    if (deals.empty())
    {
        return totalValue;
    }
    for (Deal *deal : deals)
    {
        for (const Facility &facility : deal->getFacilities())
        {
            std::vector<Lender *> lenders = facility.getLenders();
            auto it = std::find(lenders.begin(), lenders.end(), lender);
            if (it != lenders.end())
            {
                totalValue += exchange(facility.getOriginalAmount() / lenders.size(), facility.getCurrency(), currency);
            }
        }
    }
    return totalValue;
}

double Portfolio::calculateTotalRemainingValue() const
{
    double totalValue = 0.0;
    if (deals.empty())
    {
        return totalValue;
    }
    for (Deal *deal : deals)
    {
        for (const Facility &facility : deal->getFacilities())
        {
            std::vector<Lender *> lenders = facility.getLenders();
            auto it = std::find(lenders.begin(), lenders.end(), lender);
            if (it != lenders.end())
            {
                totalValue += exchange(facility.getRemainingAmount() / lenders.size(), facility.getCurrency(), currency);
            }
        }
    }
    return totalValue;
}

void Portfolio::print() const
{
    std::cout << "Portfolio contains " << deals.size() << " deals." << std::endl;
    for (Deal *deal : deals)
    {
        deal->print(2);
    }
}
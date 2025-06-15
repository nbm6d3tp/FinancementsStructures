#include "Facility.hh"
#include <iostream>
#include <iomanip>
#include "Lender.hh"
#include "Part.hh"
#include "utils.hh"

Facility::Facility(const std::string &s, const std::string &e,
                   double amt, const std::string &cur, double rate,
                   int nbParts_, const std::vector<Lender *> &l)
    : startDate(s), endDate(e), originalAmount(amt), nbParts(nbParts_),
      currency(cur), interestRate(rate), lenders(l), status(Status::PENDING) {}

double Facility::calculateInterest() const
{
    return originalAmount * interestRate * roughMonthsBetween(startDate, endDate);
}

int Facility::getNbRemainingParts() const
{
    return nbParts - static_cast<int>(paidParts.size());
}

double Facility::getNominalAmountPart() const
{
    return originalAmount / nbParts;
}

double Facility::getRemainingAmount() const
{
    return originalAmount - getNbRemainingParts() * getNominalAmountPart();
}

void Facility::print(int levelIndent) const
{
    std::cout << std::string(levelIndent, ' ') << "Facility from " << startDate
              << " to " << endDate << ", Amount: " << std::fixed << std::setprecision(2)
              << originalAmount << " " << currency
              << ", Interest Rate: " << interestRate * 100.0 << "%, "
              << "Parts: " << nbParts
              << ", Remaining Amount: " << getRemainingAmount() << std::endl;

    std::cout << std::string(levelIndent + 2, ' ') << "Lenders:" << std::endl;
    for (const Lender *lender : lenders)
    {
        std::cout << std::string(levelIndent + 4, ' ') << lender->getName() << std::endl;
    }

    if (!paidParts.empty())
    {
        std::cout << std::string(levelIndent + 2, ' ') << "Paid Parts:" << std::endl;
        for (const Part *part : paidParts)
        {
            part->print(levelIndent + 4);
        }
    }
}

const std::string Facility::getStartDate() const
{
    return startDate;
}
const std::string Facility::getEndDate() const
{
    return endDate;
}
double Facility::getOriginalAmount() const
{
    return originalAmount;
}
const std::string Facility::getCurrency() const
{
    return currency;
}
double Facility::getInterestRate() const
{
    return interestRate;
}
const std::vector<Lender *> Facility::getLenders() const
{
    return lenders;
}
const std::vector<Part *> Facility::getPaidParts() const
{
    return paidParts;
}

Status Facility::getStatus() const
{
    return status;
}
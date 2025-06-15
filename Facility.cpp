#include "Facility.hh"
#include <iostream>
#include <iomanip>
#include "Lender.hh"
#include "Part.hh"
#include "utils.hh"
#include "Currency.hh"

Facility::Facility(const std::string &s, const std::string &e,
                   double amt, const Currency cur, double rate,
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
    return getNbRemainingParts() * getNominalAmountPart();
}

void Facility::print(int levelIndent) const
{
    std::cout << std::string(levelIndent, ' ') << "Facility Details:" << std::endl;
    std::cout << std::string(levelIndent + 2, ' ') << "Start Date: " << startDate << std::endl;
    std::cout << std::string(levelIndent + 2, ' ') << "End Date: " << endDate << std::endl;
    std::cout << std::string(levelIndent + 2, ' ') << "Original Amount: "
              << std::fixed << std::setprecision(2) << originalAmount
              << " " << currencyToString(currency) << std::endl;
    std::cout << std::string(levelIndent + 2, ' ') << "Interest Rate: "
              << std::fixed << std::setprecision(2) << (interestRate * 100) << "%" << std::endl;
    std::cout << std::string(levelIndent + 2, ' ') << "Number of Parts: " << nbParts << std::endl;
    std::cout << std::string(levelIndent + 2, ' ') << "Number of Remaining Parts: "
              << getNbRemainingParts() << std::endl;
    std::cout << std::string(levelIndent + 2, ' ') << "Nominal Amount per Part: "
              << std::fixed << std::setprecision(2) << getNominalAmountPart()
              << " " << currencyToString(currency) << std::endl;
    std::cout << std::string(levelIndent + 2, ' ') << "Remaining Amount: "
              << std::fixed << std::setprecision(2) << getRemainingAmount()
              << " " << currencyToString(currency) << std::endl;
    std::cout << std::string(levelIndent + 2, ' ') << "Status: "
              << statusToString(status) << std::endl;
    std::cout << std::string(levelIndent + 2, ' ') << "Number of periods: "
              << roughMonthsBetween(startDate, endDate)
              << std::endl;
    std::cout << std::string(levelIndent + 2, ' ') << "Interest Calculation: "
              << std::fixed << std::setprecision(2) << calculateInterest()
              << " " << currencyToString(currency) << std::endl;
    std::cout
        << std::string(levelIndent + 2, ' ') << "Lenders:" << std::endl;
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
const Currency Facility::getCurrency() const
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

int Facility::getNbParts() const
{
    return nbParts;
}

void Facility::payParts(const std::string &date, double nbPartsToPay)
{
    if (nbPartsToPay <= 0)
    {
        std::cerr << "Error: Number of parts to pay must be greater than zero." << std::endl;
        return;
    }
    if (!isValidDateFormat(date))
    {
        std::cerr << "Error: Invalid date format. Expected YYYY-MM-DD." << std::endl;
        return;
    }
    if (nbPartsToPay > getNbRemainingParts())
    {
        std::cerr << "Error: Cannot pay more parts than remaining." << std::endl;
        return;
    }
    if (status != Status::ACTIVE)
    {
        std::cerr << "Error: Facility is not active. Cannot pay parts." << std::endl;
        return;
    }
    double amountPaid = nbPartsToPay * getNominalAmountPart();
    for (int i = 0; i < nbPartsToPay; ++i)
    {
        paidParts.push_back(new Part(date, getNominalAmountPart(), currency));
    }

    if (getNbRemainingParts() == 0)
    {
        status = Status::TERMINATED;
        std::cout << "Facility " << getStartDate() << " to " << getEndDate()
                  << " has been fully paid and is now terminated." << std::endl;
    }
}
void Facility::printPaidParts(int levelIndent) const
{
    if (paidParts.empty())
    {
        std::cout << std::string(levelIndent, ' ') << "No paid parts." << std::endl;
        return;
    }
    std::cout << std::string(levelIndent, ' ') << "Paid Parts:" << std::endl;

    std::map<std::string, std::vector<const Part *>> partsByDate;
    for (const Part *part : paidParts)
    {
        partsByDate[part->getPayDate()].push_back(part);
    }
    for (const auto &entry : partsByDate)
    {
        std::cout << std::string(levelIndent + 2, ' ') << "Date: " << entry.first << std::endl;
        int nbPartsOnDate = entry.second.size();
        std::cout << std::string(levelIndent + 4, ' ') << "Number of Parts: " << nbPartsOnDate << std::endl;
        std::cout << std::string(levelIndent + 4, ' ') << "Nominal Amount: "
                  << std::fixed << std::setprecision(2) << entry.second[0]->getAmount()
                  << " " << currencyToString(entry.second[0]->getCurrency()) << std::endl;
    }
}

void Facility::setStatus(const Status &st)
{
    status = st;
}
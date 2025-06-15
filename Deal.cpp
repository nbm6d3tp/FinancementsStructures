#include "Deal.hh"
#include <iostream>
#include <iomanip>

Deal::Deal(const std::string &num, Agent ag,
           const std::vector<Pool> &p, Borrower *b,
           double amt, Currency cur,
           const std::string &sig, const std::string &end,
           std::vector<Facility> &fac)
    : contractNumber(num), agent(ag), pools(p), borrower(b),
      projectAmount(amt), currency(cur), signatureDate(sig),
      endDate(end), facilities(fac)
{
    status = Status::ACTIVE;
    fac[0].setStatus(Status::ACTIVE); // Set the first facility as active
}

void Deal::print(int levelIndent) const
{
    std::cout << std::string(levelIndent, ' ') << "Deal Contract Number: " << contractNumber << std::endl;
    std::cout << std::string(levelIndent, ' ') << "Agent: ";
    agent.print();
    std::cout << std::string(levelIndent, ' ') << "Borrower: " << borrower->getName() << std::endl;
    std::cout << std::string(levelIndent, ' ') << "Project Amount: " << std::fixed << std::setprecision(2)
              << projectAmount << " " << currencyToString(currency) << std::endl;
    std::cout << std::string(levelIndent, ' ') << "Signature Date: " << signatureDate
              << ", End Date: " << endDate << std::endl;
    std::cout << std::string(levelIndent, ' ') << "Status: "
              << (status == Status::ACTIVE ? "ACTIVE" : "TERMINATED") << std::endl;

    if (!pools.empty())
    {
        std::cout << "Pools involved:" << std::endl;
        for (const Pool &pool : pools)
        {
            std::cout << std::string(levelIndent + 2, ' ') << "Pool Name: " << pool.getName() << std::endl;
        }
    }

    if (!facilities.empty())
    {
        std::cout << "Facilities involved:" << std::endl;
        for (const Facility &facility : facilities)
        {
            facility.print(levelIndent + 2);
        }
    }
}

Facility &Deal::getCurrentFacility()
{
    if (facilities.empty())
    {
        std::cerr << "No facilities available." << std::endl;
        throw std::runtime_error("No facilities available");
    }
    if (status != Status::ACTIVE)
    {
        std::cerr << "Deal is not active." << std::endl;
        throw std::runtime_error("Deal is not active");
    }
    for (Facility &facility : facilities)
    {
        if (facility.getStatus() == Status::ACTIVE)
        {
            return facility;
        }
    }
}
// double Deal::calculateTotalInterest() const
// {
//     double totalInterest = 0.0;
//     for (const Facility *facility : facilities)
//     {
//         totalInterest += facility->calculateInterest();
//     }
//     return totalInterest;
// }

// void Deal::payParts(const std::string &date, double nbParts)
// {
//     if (facilities.empty())
//     {
//         std::cerr << "No facilities available to pay parts." << std::endl;
//         return;
//     }
//     facilities.back()->payParts(date, nbParts);
// }

// void Deal::print() const
// {
//     std::cout << "Deal Contract Number: " << contractNumber << std::endl;
//     std::cout << "Agent: ";
//     agent->print();
//     std::cout << "Borrower: " << borrower->getName() << std::endl;
//     std::cout << "Project Amount: " << std::fixed << std::setprecision(2) << projectAmount
//               << " " << (currency == Currency::EUR ? "EUR" : "Other") << std::endl;
//     std::cout << "Signature Date: " << signatureDate << ", End Date: " << endDate << std::endl;
//     std::cout << "Status: " << (status == Status::ACTIVE ? "ACTIVE" : "TERMINATED") << std::endl;

//     if (!pools.empty())
//     {
//         std::cout << "Pools involved:" << std::endl;
//         for (const Pool *pool : pools)
//         {
//             pool->print();
//         }
//     }

//     if (!facilities.empty())
//     {
//         std::cout << "Facilities involved:" << std::endl;
//         for (const Facility *facility : facilities)
//         {
//             facility->print();
//         }
//     }
// }

// Getters
const std::string Deal::getContractNumber() const
{
    return contractNumber;
}
const Agent &Deal::getAgent() const
{
    return agent;
}
const std::vector<Pool> &Deal::getPools() const
{
    return pools;
}
const Borrower *Deal::getBorrower() const
{
    return borrower;
}
double Deal::getProjectAmount() const
{
    return projectAmount;
}
Currency Deal::getCurrency() const
{
    return currency;
}
const std::string Deal::getSignatureDate() const
{
    return signatureDate;
}
const std::string Deal::getEndDate() const
{
    return endDate;
}
Status Deal::getStatus() const
{
    return status;
}
const std::vector<Facility> &Deal::getFacilities() const
{
    return facilities;
}
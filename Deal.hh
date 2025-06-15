#pragma once

#include <string>
#include <vector>
#include "Agent.hh"
#include "Borrower.hh"
#include "Facility.hh"
#include "Pool.hh"
#include "Currency.hh"
#include "Status.hh"

class Deal
{
private:
    std::string contractNumber; // S/Z/B + 4 digits
    Agent agent;
    std::vector<Pool> pools;

    Borrower *borrower;
    double projectAmount;
    Currency currency;
    std::string signatureDate;
    std::string endDate;
    Status status;

    std::vector<Facility> facilities;

public:
    Deal(const std::string &num, Agent ag,
         const std::vector<Pool> &p, Borrower *b,
         double amt, Currency cur,
         const std::string &sig, const std::string &end,
         std::vector<Facility> &fac);

    Facility &getCurrentFacility();
    // double calculateTotalInterest() const;
    // void payParts(const std::string &date, double nbParts);
    void print(int levelIndent) const;

    // Getters
    const std::string getContractNumber() const;
    const Agent &getAgent() const;
    const std::vector<Pool> &getPools() const;
    const Borrower *getBorrower() const;
    double getProjectAmount() const;
    Currency getCurrency() const;
    const std::string getSignatureDate() const;
    const std::string getEndDate() const;
    Status getStatus() const;
    const std::vector<Facility> &getFacilities() const;
};
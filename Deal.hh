#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "Agent.hh"
#include "Borrower.hh"
#include "Facility.hh"
#include "Pool.hh"
#include "Currency.hh"
#include "Status.hh"
using namespace std;

class Deal
{
private:
    string contractNumber; // S/Z/B + 4 digits
    Agent agent;
    vector<Pool> pools;

    Borrower borrower;
    double projectAmount;
    Currency currency;
    string signatureDate;
    string endDate;
    Status status;

    vector<Facility> facilities;

public:
    Deal(const string num, Agent ag,
         const vector<Pool> p, Borrower b,
         double amt, const Currency cur,
         const string sig, const string end, const vector<Facility> fac)
        : contractNumber(num), agent(ag), pools(p), borrower(b),
          projectAmount(amt), currency(cur), signatureDate(sig),
          endDate(end), facilities(fac)
    {
        status = Status::ACTIVE;
    }

    Facility getCurrentFacility() const
    {
        return facilities[0];
    }

    double calculateTotalInterest() const
    {
        double totalInterest = 0.0;

        for (const Facility facility : facilities)
        {
            totalInterest += facility.calculateInterest();
        }

        return totalInterest;
    }

    void payParts(string date, double nbParts)
    {
        Facility currentFacility = getCurrentFacility();
        if (currentFacility.getNbRemainingParts() >= nbParts)
        {
            currentFacility.payParts(date, nbParts);
            cout << "Paid " << nbParts << " parts on " << date << endl;
        }
        else
        {
            cout << "Not enough remaining parts to pay." << endl;
        }
    }

    void print() const
    {
        cout << "Deal Contract Number: " << contractNumber << endl;
        cout << "Agent: " << agent.getName() << endl;
        cout << "Borrower: " << borrower.getName() << endl;
        cout << "Project Amount: " << projectAmount << " " << currencyToString(currency) << endl;
        cout << "Signature Date: " << signatureDate << ", End Date: " << endDate << endl;
        cout << "Status: " << (status == Status::ACTIVE ? "Active" : "Terminated") << endl;

        for (const Pool &pool : pools)
        {
            pool.print();
        }

        for (const Facility &facility : facilities)
        {
            facility.print();
        }
    }
};
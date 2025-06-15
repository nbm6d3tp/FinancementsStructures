#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "Lender.hh"
#include "Part.hh"
#include "utils.hh"
#include "Status.hh"
using namespace std;

class Facility
{
private:
    string startDate;
    string endDate;
    double originalAmount;
    int nbParts;
    string currency;
    double interestRate; // 0.05 = 5 % / month

    vector<Lender> lenders;
    vector<Part> paidParts;
    Status status;

public:
    Facility(const string s, const string e,
             double amt, const string cur, double rate, int nbParts, const vector<Lender> l)
        : startDate(s), endDate(e), originalAmount(amt), currency(cur), interestRate(rate), nbParts(nbParts), lenders(l)
    {
    }

    double calculateInterest() const
    {
        return originalAmount * interestRate * roughMonthsBetween(startDate, endDate);
    }

    double getRemainingAmount() const
    {
        double totalPaid = 0.0;
        for (const auto part : paidParts)
        {
            totalPaid += part.getAmount();
        }
        return originalAmount - totalPaid;
    }

    int getNbRemainingParts() const
    {
        return nbParts - paidParts.size();
    }

    double getNominalAmountPart() const
    {
        return originalAmount / nbParts;
    }
    void print() const
    {
        cout << "Facility from " << startDate << " to " << endDate
             << ", Amount: " << originalAmount << " " << currency
             << ", Interest Rate: " << fixed << setprecision(2)
             << (interestRate * 100) << "%, Lenders: ";
        for (const Lender &lender : lenders)
        {
            cout << lender.getName() << " ";
        }
        cout << endl;

        for (const Part &part : paidParts)
        {
            part.print();
        }
    }

    const string getStartDate() const
    {
        return startDate;
    }
    const string getEndDate() const
    {
        return endDate;
    }
    double getOriginalAmount() const
    {
        return originalAmount;
    }
    const string getCurrency() const
    {
        return currency;
    }
    double getInterestRate() const
    {
        return interestRate;
    }
    const vector<Lender> &getLenders() const
    {
        return lenders;
    }
    const vector<Part> &getPaidParts() const
    {
        return paidParts;
    }
    Status getStatus() const
    {
        return status;
    }

    void payParts(const string &date, double nbParts)
    {
        if (getNbRemainingParts() >= nbParts)
        {
            double amountPerPart = getNominalAmountPart();
            for (int i = 0; i < nbParts; ++i)
            {
                paidParts.push_back(Part(date, amountPerPart));
            }
            cout << "Paid " << nbParts << " parts on " << date << endl;
        }
        else
        {
            cout << "Not enough remaining parts to pay." << endl;
        }
    }
};
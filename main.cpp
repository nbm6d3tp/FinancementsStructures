#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <fcntl.h>
#include <io.h>
#include "Borrower.hh"
#include "Lender.hh"
#include "Agent.hh"
#include "Pool.hh"
#include "Facility.hh"
#include "Deal.hh"
#include "Currency.hh"

using namespace std;

int main()
{
    Borrower af("Air France");
    Lender bnp("BNP Paribas");
    Lender sg("Societe Generale");
    Lender ca("Credit Agricole");

    Deal deal("D12345", Agent(&bnp), {Pool(&sg), Pool(&ca)}, &af, Currency::EUR, "2023-01-01", "2025-01-01", {Facility("2023-01-01", "2025-01-01", 500000.0, Currency::USD, 0.05, 10, {&bnp, &sg}), Facility("2023-06-01", "2025-06-01", 500000.0, Currency::JPY, 0.04, 10, {&ca})});
    deal.print(0);

    try
    {
        deal.payParts("2023-02-01", 2);
        deal.getCurrentFacility().print(0);
        std::cout << "Remaining amount after payment: " << std::fixed << std::setprecision(2)
                  << deal.getRemainingAmount() << " " << currencyToString(deal.getCurrency()) << std::endl;
        }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}

// g++ Agent.cpp Borrower.cpp Lender.cpp Pool.cpp Facility.cpp main.cpp -o main
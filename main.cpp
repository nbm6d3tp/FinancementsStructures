#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "Borrower.hh"
#include "Lender.hh"
#include "Agent.hh"
#include "Pool.hh"
#include "Deal.hh"
#include "Facility.hh"
#include "Currency.hh"
#include "Status.hh"
#include "Exchange.hh"
#include "utils.hh"
#include "Part.hh"
#include "Portfolio.hh"

using namespace std;

int main()
{
    Borrower af("Air France");
    // Lender bnp("BNP Paribas");
    // Lender sg("Société Générale");
    // Lender ca("Crédit Agricole");

    af.print();
    // bnp.print();
    // sg.print();
    // ca.print();

    // Deal deal("D12345", Agent(&bnp), {Pool(&sg), Pool(&ca)}, af, 1000000.0, Currency::EUR, "2023-01-01", "2025-01-01", {Facility("2023-01-01", "2025-01-01", 500000.0, "EUR", 0.05, {bnp, sg}, 10), Facility("2023-06-01", "2025-06-01", 500000.0, "EUR", 0.04, {ca}, 10)});
    // deal.print();
}

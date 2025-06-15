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

    Deal deal("D12345", Agent(&bnp), {Pool(&sg), Pool(&ca)}, &af, 1000000.0, Currency::EUR, "2023-01-01", "2025-01-01", {Facility("2023-01-01", "2025-01-01", 500000.0, "EUR", 0.05, 10, {&bnp, &sg}), Facility("2023-06-01", "2025-06-01", 500000.0, "EUR", 0.04, 10, {&ca})});
}

// g++ Agent.cpp Borrower.cpp Lender.cpp Pool.cpp Facility.cpp main.cpp -o main
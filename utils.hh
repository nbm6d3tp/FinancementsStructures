#pragma once
#include <string>
#include <iomanip>
using namespace std;

int roughMonthsBetween(string startDate, string endDate)
{
    // Assuming startDate and endDate are in the format "YYYY-MM-DD"
    int startYear = stoi(startDate.substr(0, 4));
    int startMonth = stoi(startDate.substr(5, 2));
    int endYear = stoi(endDate.substr(0, 4));
    int endMonth = stoi(endDate.substr(5, 2));

    // Calculate the difference in months
    return (endYear - startYear) * 12 + (endMonth - startMonth);
}
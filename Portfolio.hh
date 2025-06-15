class Portfolio
{
private:
    vector<Deal> deals;

public:
    void addDeal(Deal d)
    {
        deals.push_back(d);
    }
    double calculateTotalInterest() const
    {
        double totalInterest = 0.0;
        for (const Deal &deal : deals)
        {
            totalInterest += deal.calculateTotalInterest();
        }
        return totalInterest;
    }
    void print() const
    {
        cout << "Portfolio contains " << deals.size() << " deals." << endl;
        for (const Deal &deal : deals)
        {
            deal.print();
        }
    }
    const vector<Deal> &getDeals() const
    {
        return deals;
    }
};
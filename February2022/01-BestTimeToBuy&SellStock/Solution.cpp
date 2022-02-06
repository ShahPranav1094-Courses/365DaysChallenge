// TLE
// O(N*N) Time & O(1) Space
int maxProfit(vector<int> &prices)
{
    int profit = 0;
    for (int i = 1; i < prices.size(); ++i)
        for (int j = 0; j < i; ++j)
            if (prices[j] < prices[i])
                profit = max(profit, prices[i] - prices[j]);
    return profit;
}

// O(N) Time & O(1) Space
int maxProfit(vector<int> &prices)
{
    int profit = 0;
    int max_until_now = prices[0], min_until_now = prices[0];
    for (int i = 1; i < prices.size(); ++i)
    {
        if (prices[i] >= max_until_now)
        {
            max_until_now = prices[i];
            profit = max(profit, max_until_now - min_until_now);
        }
        else if (prices[i] < min_until_now)
        {
            min_until_now = prices[i];
            max_until_now = prices[i];
        }
    }
    return profit;
}

// Optimized
// O(N) Time & O(1) Space
int maxProfit(vector<int> &prices)
{
    int profit = 0;
    int min_until_now = INT_MAX;
    for (auto &price : prices)
    {
        min_until_now = min(min_until_now, price);
        profit = max(profit, price - min_until_now);
    }
    return profit;
}
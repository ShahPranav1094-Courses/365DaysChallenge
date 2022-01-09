// O(N) Time & O(1) Space
int maximumWealth(vector<vector<int>> &accounts)
{
    int maxWealth = 0;
    for (auto account : accounts)
    {
        int tempWealth = 0;
        maxWealth = max(maxWealth, std::accumulate(account.begin(), account.end(), tempWealth));
    }
    return maxWealth;
}
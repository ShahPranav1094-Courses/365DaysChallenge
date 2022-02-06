// O(N) Time & O(1) Space
int largestAltitude(vector<int> &gain)
{
    int ele = max(0, gain[0]);
    for (int i = 1; i < gain.size(); ++i)
    {
        gain[i] = gain[i] + gain[i - 1];
        ele = max(ele, gain[i]);
    }
    return ele;
}

// O(N) Time & O(1) Space
int largestAltitude(vector<int> &gain)
{
    int curr_alt = 0, max_alt = 0;
    for (auto &curr : gain)
    {
        curr_alt += curr;
        max_alt = max(max_alt, curr_alt);
    }
    return max_alt;
}
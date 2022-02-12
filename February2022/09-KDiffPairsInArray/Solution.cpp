// O(N) Time & O(N) Space
int findPairs(vector<int> &nums, int k)
{
    unordered_map<int, int> numToCount;
    unordered_set<int> s;
    for (int i = 0; i < nums.size(); ++i)
    {
        if (numToCount.count(nums[i] - k))
            s.insert(nums[i] - k);
        if (numToCount.count(nums[i] + k))
            s.insert(nums[i]);
        numToCount[nums[i]] += 1;
    }
    return s.size();
}
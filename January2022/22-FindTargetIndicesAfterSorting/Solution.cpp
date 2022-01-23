// O(NlogN) Time & O(1) Space
vector<int> targetIndices(vector<int> &nums, int target)
{
    sort(nums.begin(), nums.end());
    vector<int> ans;
    for (int i = 0; i < nums.size(); ++i)
    {
        if (nums[i] == target)
        {
            ans.push_back(i);
        }
    }
    return ans;
}

// O(N) Time & O(1) Space
vector<int> targetIndices(vector<int> &nums, int target)
{
    vector<int> ans;
    int cnt = 0;
    int rank = 0;
    for (auto i : nums)
    {
        cnt += i == target;
        rank += i < target;
    }
    while (cnt--)
    {
        ans.push_back(rank++);
    }
    return ans;
}
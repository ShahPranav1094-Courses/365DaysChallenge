// O(N) Time & O(N) Space
vector<int> buildArray(vector<int> &nums)
{
    vector<int> ans(nums.size(), 0);
    for (int i = 0; i < nums.size(); ++i)
        ans[i] = nums[nums[i]];
    return ans;
}

// O(N) Time & O(1) Space
// modulo by n gives input array value
// divide by n gives modified value 
vector<int> buildArray(vector<int> &nums)
{
    int n = nums.size();
    for (int i = 0; i < n; ++i)
        nums[i] = nums[i] + (n * (nums[nums[i]] % n));
    for (int i = 0; i < n; ++i)
        nums[i] /= n;
    return nums;
}

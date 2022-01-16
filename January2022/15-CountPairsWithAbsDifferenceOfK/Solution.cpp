// O(N) Time & O(N) Space
int countKDifference(vector<int>& nums, int k) {
        unordered_map<int, int> s;
        int count = 0;
        for(int i=0; i < nums.size(); ++i)
        {
            count += s[nums[i] + k] + s[nums[i] - k];
            s[nums[i]]++;
        }
        return count;
    }

// Use of constraints
// O(N) Time & O(constraints) Space
int countKDifference(vector<int> &nums, int k)
{
    vector<int> cnt(101, 0);
    for (int i = 0; i < nums.size(); ++i)
        cnt[nums[i]]++;
    int res = 0;
    for (int i = k + 1; i < 101; ++i)
        res += cnt[i] * cnt[i - k];
    return res;
}
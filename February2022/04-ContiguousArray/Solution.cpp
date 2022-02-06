// O(N) Time & O(N) Space
// https://leetcode.com/problems/contiguous-array/solution/
int findMaxLength(vector<int> &nums)
{
    unordered_map<int, int> m;
    m[0] = -1;
    int sum = 0;
    int max_count = 0;
    for (int i = 0; i < nums.size(); ++i)
    {
        sum += nums[i] == 0 ? -1 : 1;
        if (m.count(sum))
            max_count = max(max_count, i - m[sum]);
        else
            m[sum] = i;
    }
    return max_count;
}
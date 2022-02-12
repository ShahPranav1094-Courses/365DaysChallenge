// https://leetcode.com/problems/subarray-sum-equals-k/discuss/1759909/C%2B%2Bor-Full-explained-every-step-w-Dry-run-or-O(n2)-greater-O(n)-or-Two-approaches
// O(N) Time & O(N) Space
int subarraySum(vector<int> &nums, int k)
{
    int sum = 0;
    int cnt = 0;
    unordered_map<int, int> m;
    m[0] = 1;
    for (int i = 0; i < nums.size(); ++i)
    {
        sum += nums[i];
        cnt += m[sum - k];
        m[sum]++;
    }
    return cnt;
}
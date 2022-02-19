// O(N) Time & O(1) Space
int singleNumber(vector<int> &nums)
{
    int run_sum = 0;
    for (auto i : nums)
        run_sum ^= i;
    return run_sum;
}
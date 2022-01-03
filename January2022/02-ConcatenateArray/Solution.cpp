// O(N) Time & O(N) Space
vector<int> getConcatenation(vector<int> &nums)
{
    nums.insert(nums.end(), nums.begin(), nums.end());
    return nums;
}
// O(N) Time & O(N) Space
vector<string> summaryRanges(vector<int> &nums)
{
    if (nums.empty())
        return vector<string>{};

    vector<string> ans;
    vector<int> temp{nums[0]};
    for (int i = 1; i < nums.size(); ++i)
    {
        if ((long long)nums[i] - (long long)nums[i - 1] != 1)
        {
            string s = temp.size() == 1 ? to_string(temp[0]) : to_string(temp.front()) + "->" + to_string(temp.back());
            ans.push_back(s);
            temp.clear();
        }
        temp.push_back(nums[i]);
    }
    string s = temp.size() == 1 ? to_string(temp[0]) : to_string(temp.front()) + "->" + to_string(temp.back());
    ans.push_back(s);
    return ans;
}
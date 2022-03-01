// O(N) Time & O(N) Space
vector<int> countBits(int n)
{
    if (n == 0)
        return {0};
    if (n == 1)
        return {0, 1};
    if (n == 2)
        return {0, 1, 1};

    vector<int> ans{0, 1, 1};
    for (int i = 3; i <= n; ++i)
    {
        int modnum = i / 2;
        int numOfOnes = i % 2 ? 1 + ans[modnum] : ans[modnum];
        ans.push_back(numOfOnes);
    }
    return ans;
}
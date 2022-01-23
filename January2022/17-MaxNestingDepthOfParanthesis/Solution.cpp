// O(N) Time & O(1) Space
int maxDepth(string s)
{
    int ob = 0;
    int ans = 0;
    for (const auto &i : s)
    {
        if (i == '(')
            ans = max(ans, ++ob);
        else if (i == ')')
            --ob;
    }

    return ans;
}
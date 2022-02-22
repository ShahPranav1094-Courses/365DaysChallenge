// O(N) Time & O(1) Space
int titleToNumber(string columnTitle)
{
    int len = columnTitle.size();
    int ans = 0;
    for (int i = 0; i < len; ++i)
    {
        ans = ans + (pow(26, i) * (columnTitle[len - i - 1] - 'A' + 1));
    }
    return ans;
}

// Optimized
// O(N) Time & O(1) Space
int titleToNumber(string columnTitle)
{
    int result = 0;
    for (char c : columnTitle)
    {
        int d = c - 'A' + 1;
        result = result * 26 + d;
    }
    return result;
}

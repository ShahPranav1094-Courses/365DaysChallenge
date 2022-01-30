// O(N+26) Time & O(26) Space
bool checkIfPangram(string sentence)
{
    vector<bool> ans(26, false);
    for (auto i : sentence)
        ans[i - 'a'] = true;
    for (auto i = 0; i < 26; ++i)
        if (!ans[i])
            return false;
    return true;
}

// O(N+26) Time & O(1) Space
bool checkIfPangram(string sentence)
{
    int seen = 0;
    for (auto i : sentence)
    {
        int ci = i - 'a';
        seen = seen | (1 << ci);
    }
    return seen == ((1 << 26) - 1);
}
// O(N) Time & O(N) Space
string restoreString(string s, vector<int> &indices)
{
    string ans(s);
    for (int i = 0; i < s.size(); ++i)
    {
        ans[indices[i]] = s[i];
    }
    return ans;
}

// O(N) Time & O(1) Space
string restoreString(string s, vector<int> &indices)
{
    int i = 0;
    while (i < s.size())
    {
        if (i != indices[i])
        {
            swap(s[i], s[indices[i]]);
            swap(indices[indices[i]], indices[i]);
        }
        else
            ++i;
    }
    return s;
}
// O(N) Time & O(26) = O(1) Space
char findTheDifference(string s, string t)
{
    vector<int> v(26, 0);
    int i = 0;
    while (i < s.size())
    {
        v[t[i] - 'a']++;
        v[s[i] - 'a']--;
        ++i;
    }
    v[t[i] - 'a']++;

    for (int i = 0; i < 26; ++i)
        if (v[i] > 0)
            return char(i + 'a');
    return ' ';
}

// XOR solution
// O(N) Time & O(1) Space
char findTheDifference(string s, string t)
{
    char c = 0;
    int i = 0;
    while (i < s.size())
    {
        c ^= s[i] ^ t[i];
        ++i;
    }
    return c ^= t[i];
}
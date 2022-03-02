// O(N) Time & O(1) Space
bool isSubsequence(string s, string t)
{
    if (t.length() < s.length())
        return false;

    int i = 0, j = 0;
    while (i < s.length() && j < t.length())
    {
        if (s[i] == t[j++])
            ++i;
    }

    return i == s.length();
}
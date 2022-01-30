// O(N) Time & O(1) Space
string replaceDigits(string s)
{
    for (int i = 1; i < s.size(); i = i + 2)
    {
        s[i] = s[i - 1] + (s[i] - '0');
    }
    return s;
}

// O(N) Time & O(1) Space
string replaceDigits(string s)
{
    for (int i = 1; i < s.size(); i += 2)
    {
        s[i] += s[i - 1] - '0';
    }
    return s;
}
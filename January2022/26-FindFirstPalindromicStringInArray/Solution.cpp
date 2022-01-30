// O(N) Time & O(1) Space
string firstPalindrome(vector<string> &words)
{
    for (auto str : words)
    {
        int lo = 0, hi = str.size() - 1;
        bool isPalindrome = true;
        while (lo < hi)
        {
            if (str[lo++] != str[hi--])
            {
                isPalindrome = !isPalindrome;
                break;
            }
        }
        if (isPalindrome)
            return str;
    }
    return "";
}

// O(N) Time & O(1) Space
string firstPalindrome(vector<string> &words)
{
    for (auto str : words)
    {
        int lo = 0, hi = str.size() - 1;
        while (lo < hi && str[lo] == str[hi])
        {
            ++lo;
            --hi;
        }
        if (lo >= hi)
            return str;
    }
    return "";
}

// O(N) Time & O(1) Space
string firstPalindrome(vector<string> &words)
{
    for (auto &str : words)
    {
        if (equal(begin(str), end(str), rbegin(str)))
            return str;
    }
    return "";
}
// O(N*26) = O(N) Time & O(26) = O(1) Space
// https://leetcode.com/problems/find-all-anagrams-in-a-string/discuss/1738073/Short-and-simple-C%2B%2B-sliding-window-solution
bool CountAllZeros(int *a)
{
    for (int i = 0; i < 26; ++i)
        if (a[i] != 0)
            return false;
    return true;
}

vector<int> findAnagrams(string s, string p)
{
    vector<int> v;
    if (p.length() > s.length())
        return v;
    int a[26]{0};

    for (int i = 0; i < p.size(); ++i)
    {
        a[s[i] - 'a']--;
        a[p[i] - 'a']++;
    }
    if (CountAllZeros(a))
        v.push_back(0);

    for (int i = p.size(); i < s.size(); ++i)
    {
        a[s[i] - 'a']--;
        a[s[i - p.size()] - 'a']++;
        if (CountAllZeros(a))
            v.push_back(i - p.size() + 1);
    }
    return v;
}
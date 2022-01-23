// O(N+M) Time & O(M+N) Space
bool arrayStringsAreEqual(vector<string> &word1, vector<string> &word2)
{
    string s1, s2;
    for (auto w1 : word1)
        s1 += w1;
    for (auto w2 : word2)
        s2 += w2;

    return s1 == s2;
}

// O(N+M) Time & O(1) Space
bool arrayStringsAreEqual(vector<string> &word1, vector<string> &word2)
{
    int i = 0, j = 0; // word pointers
    int m = 0, n = 0; // char pointers

    while (i < word1.size() and j < word2.size())
    {
        if (word1[i][m++] != word2[j][n++])
            return false;

        if (m >= word1[i].size())
            i++, m = 0;

        if (n >= word2[j].size())
            j++, n = 0;
    }

    return i == word1.size() and j == word2.size();
}
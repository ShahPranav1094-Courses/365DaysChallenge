// O(N) Time & O(128) Space
string removeDuplicateLetters(string s)
{
    vector<int> dict(128, 0);
    vector<bool> visited(128, false);
    string res;
    for (auto c : s)
        dict[c]++;
    for (auto c : s)
    {
        dict[c]--;
        if (visited[c])
            continue;
        while (!res.empty() && res.back() > c && dict[res.back()])
        {
            visited[res.back()] = false;
            res.pop_back();
        }
        visited[c] = true;
        res += c;
    }
    return res;
}
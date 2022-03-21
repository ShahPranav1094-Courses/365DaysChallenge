// O(N) Time & O(1) Space
vector<int> partitionLabels(string s)
{
    vector<int> v(26, 0);
    vector<int> ans;
    for (int i = 0; i < s.length(); ++i)
        v[s[i] - 'a'] = i;
    int start = 0, end = 0;
    for (int i = 0; i < s.length(); ++i)
    {
        end = max(end, v[s[i] - 'a']);
        if (end == i)
        {
            ans.push_back(end - start + 1);
            start = end + 1;
        }
    }
    return ans;
}
// O(N) Time & O(N) Space
string removeKdigits(string num, int k)
{
    stack<char> s;
    s.push(num[0]);
    int i = 1;
    while (i < num.size())
    {
        while (k > 0 && !s.empty() && ((num[i] - '0') < (s.top() - '0')))
        {
            s.pop();
            --k;
        }
        s.push(num[i++]);
    }
    while (k > 0)
    {
        s.pop();
        --k;
    }

    string ans;

    while (!s.empty())
    {
        char t = s.top();
        s.pop();
        ans.push_back(t);
    }
    while (ans.back() == '0')
    {
        ans.pop_back();
    }
    if (ans.empty())
        ans.push_back('0');
    std::reverse(begin(ans), end(ans));
    return ans;
}
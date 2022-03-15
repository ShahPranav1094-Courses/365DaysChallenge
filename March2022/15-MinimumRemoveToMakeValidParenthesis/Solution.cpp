// O(N) Time & O(N) Space
string minRemoveToMakeValid(string s)
{
    stack<int> stk;
    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] == '(')
            stk.push(i);
        else if (s[i] == ')')
        {
            if (stk.empty())
                s[i] = '#';
            else
                stk.pop();
        }
    }

    while (!stk.empty())
    {
        s[stk.top()] = '#';
        stk.pop();
    }

    string ans;
    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] != '#')
            ans.push_back(s[i]);
    }
    return ans;
}
// O(N) Time & O(N) Space
bool isValid(string s)
{
    stack<char> stk;
    for (auto i : s)
    {
        if (i == '(' || i == '{' || i == '[')
            stk.push(i);
        else
        {
            if (stk.empty())
                return false;
            char c = stk.top();
            stk.pop();
            if ((i == ')' && i - c != 1) || (i > ')' && i - c != 2))
                return false;
        }
    }
    return stk.empty() ? true : false;
}
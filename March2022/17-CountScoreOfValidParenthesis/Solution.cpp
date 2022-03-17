// O(N) Time & O(N) Space
// https://leetcode.com/problems/score-of-parentheses/discuss/1856417/C%2B%2B-oror-Explained-With-Algorithm-oror-0ms-oror-100-oror-Easy-and-Simple
int scoreOfParentheses(string s)
{
    stack<int> stk;
    stk.push(0);
    for (auto i : s)
    {
        if (i == '(')
            stk.push(0);
        else
        {
            int temp = stk.top();
            stk.pop();
            stk.top() += temp ? 2 * temp : 1;
        }
    }
    return stk.top();
}
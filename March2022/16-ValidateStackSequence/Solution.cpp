// O(N) Time & O(N) Space
bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
{
    stack<int> s;
    int j = 0;
    int N = pushed.size();
    for (auto p : pushed)
    {
        s.push(p);
        while (!s.empty() && j < N && s.top() == popped[j])
        {
            s.pop();
            ++j;
        }
    }
    return j == N;
}
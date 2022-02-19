// https://leetcode.com/problems/minimize-deviation-in-array/discuss/955262/C%2B%2B-intuitions-and-flip

// O(N) Time & O(N) Space
int minimumDeviation(vector<int> &nums)
{
    int res = INT_MAX, min_num = INT_MAX;
    priority_queue<int> p;
    for (auto &n : nums)
    {
        n = n % 2 ? n * 2 : n;
        min_num = min(min_num, n);
        p.push(n);
    }

    while (p.top() % 2 == 0)
    {
        res = min(res, p.top() - min_num);
        min_num = min(min_num, p.top() / 2);
        p.push(p.top() / 2);
        p.pop();
    }
    return min(res, p.top() - min_num);
}
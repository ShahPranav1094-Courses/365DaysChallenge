// O(NlogN) Time & O(K) Space
class KthLargest
{
    priority_queue<int, vector<int>, greater<int> > pq;
    int sz = 0;

public:
    KthLargest(int k, vector<int> &nums)
    {
        sz = k;
        for (auto &num : nums)
        {
            if (k > 0)
            {
                --k;
                pq.push(num);
            }
            else if (num > pq.top())
            {
                pq.pop();
                pq.push(num);
            }
        }
    }

    int add(int val)
    {
        if (pq.size() < sz)
            pq.push(val);
        else if (val > pq.top())
        {
            pq.pop();
            pq.push(val);
        }
        return pq.top();
    }
};

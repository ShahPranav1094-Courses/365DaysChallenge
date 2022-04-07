// O(NlogN) Time & O(N) Space
int lastStoneWeight(vector<int> &stones)
{
    priority_queue<int> pq;
    for (auto stone : stones)
        pq.push(stone);

    int hi = 0, shi = 0;
    while (pq.size() >= 2)
    {
        hi = pq.top();
        pq.pop();
        shi = pq.top();
        pq.pop();

        if (hi != shi)
            pq.push(hi - shi);
    }

    return pq.empty() ? 0 : pq.top();
}
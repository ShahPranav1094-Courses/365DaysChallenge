// O(N) Time & O(N) Space
int findCenter(vector<vector<int>> &edges)
{
    unordered_map<int, int> cnt;
    for(int i=0; i < edges.size(); ++i)
    {
        if(++cnt[edges[i][0]] > 1)
            return edges[i][0];
        if(++cnt[edges[i][1]] > 1)
            return edges[i][1];
    }
    return 0;
    if(edges[0][0] == edges[1][0] || edges[0][0] == edges[1][1])
        return edges[0][0];
    return edges[0][1];
}

// O(1) Time & O(1) Space
int findCenter(vector<vector<int>> &edges)
{
    return edges[0][0] == edges[1][0] || edges[0][0] == edges[1][1] ? edges[0][0] : edges[0][1];
}
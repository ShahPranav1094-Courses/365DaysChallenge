// O(NlogN) Time & O(sort) Space
int removeCoveredIntervals(vector<vector<int>> &intervals)
{
    sort(intervals.begin(), intervals.end(), [](const vector<int> &interval1, const vector<int> &interval2)
         { return interval1[0] < interval2[0]; });

    int count = 1;
    vector<int> curr_interval = intervals[0];
    for (int i = 1; i < intervals.size(); ++i)
    {
        if (intervals[i][0] > curr_interval[0] && intervals[i][1] > curr_interval[1])
        {
            ++count;
            curr_interval = intervals[i];
        }
        curr_interval[1] = max(curr_interval[1], intervals[i][1]);
    }
    return count;
}
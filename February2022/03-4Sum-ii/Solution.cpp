// TLE
// O(N*N*N) Time & O(N) Space
int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4)
{
    int ans = 0;
    unordered_map<int, int> m;
    for (int i = 0; i < nums1.size(); ++i)
    {
        for (int j = 0; j < nums2.size(); ++j)
        {
            for (int k = 0; k < nums3.size(); ++k)
            {
                m[nums1[i] + nums2[j] + nums3[k]]++;
            }
        }
    }

    for (int i = 0; i < nums4.size(); ++i)
    {
        int temp = -1 * nums4[i];
        ans += m[temp];
    }
    return ans;
}

// Optimized
// O(N*N) Time & O(2*N) = O(N) Space
int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4)
{
    int ans = 0;
    unordered_map<int, int> m;
    for (auto &first : nums1)
        for (auto &second : nums2)
            m[first + second]++;
    for (auto &third : nums3)
        for (auto &fourth : nums4)
            if (m.count(-third - fourth))
                ans += m[-third - fourth];
    return ans;
}
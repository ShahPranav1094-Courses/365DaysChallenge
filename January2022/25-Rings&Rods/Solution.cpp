// O(N) Time & O(1) Space
int countPoints(string rings)
{
    vector<int> nums(10, 0);
    int len = rings.size();
    for (int i = 1; i < len; i = i + 2)
    {
        int idx = rings[i] - '0';
        if (rings[i - 1] == 'R')
            nums[idx] = nums[idx] | 1 << 0;
        else if (rings[i - 1] == 'G')
            nums[idx] = nums[idx] | 1 << 1;
        else
            nums[idx] = nums[idx] | 1 << 2;
    }
    int ans = 0;
    for (int i = 0; i < 10; ++i)
    {
        if (((1 << 3) - 1) == nums[i])
            ++ans;
    }
    return ans;
}

// Optimized
// O(N) Time & O(1) Space
int countPoints(string rings)
{
    int rods[10] = {};
    for (int i = 0; i < rings.size(); i += 2)
    {
        int color = rings[i] == 'R' ? 1 : rings[i] == 'G' ? 2
                                                          : 4;
        rods[rings[i + 1] - '0'] |= color;
    }
    return count(begin(rods), end(rods), 7);
}
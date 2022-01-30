// O(NlogN) Time & O(1) Space
int maxProductDifference(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    return ((nums[nums.size() - 1] * nums[nums.size() - 2]) - (nums[0] * nums[1]));
}

// O(N) Time & O(1) Space
int maxProductDifference(vector<int> &nums)
{
    int max1 = 0, max2 = 0, min1 = INT_MAX, min2 = INT_MAX;
    for (auto i : nums)
    {
        if (i > max1)
        {
            max2 = max1;
            max1 = i;
        }
        else
            max2 = max(max2, i);

        if (i < min1)
        {
            min2 = min1;
            min1 = i;
        }
        else
            min2 = min(min2, i);
    }
    return ((max1 * max2) - (min1 * min2));
}

// O(N) Time & O(1) Space
int maxProductDifference(vector<int> &nums)
{
    int a = INT_MIN, b = INT_MIN, c = INT_MAX, d = INT_MAX;
    for (int &i : nums)
    {
        if (i > a || i > b)
        {
            b = max(b, a);
            a = i;
        }
        if (i < c || i < d)
        {
            d = min(d, c);
            c = i;
        }
    }

    return (a * b) - (c * d);
}
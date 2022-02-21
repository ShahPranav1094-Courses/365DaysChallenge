// O(N) Time & O(1) Space
int majorityElement(vector<int> &nums)
{
    int count = 0, majority_element = 0;
    for (auto &i : nums)
    {
        if (count == 0)
            majority_element = i;

        if (i == majority_element)
            ++count;
        else
            --count;
    }
    return majority_element;
}
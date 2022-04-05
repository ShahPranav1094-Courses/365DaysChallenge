// O(N) Time & O(1) Space
int maxArea(vector<int> &height)
{
    int j = height.size() - 1;
    int i = 0;
    int maxArea = 0;
    int length = 0;
    int breadth = 0;
    int area = 0;
    while (i < j)
    {
        length = j - i;
        breadth = height[i] < height[j] ? height[i++] : height[j--];
        area = length * breadth;
        if (maxArea < area)
            maxArea = area;
    }
    return maxArea;
}

// O(N) Time & O(1) Space
int numberOfSteps(int num)
{
    int ans = 0;
    while (num)
    {
        if (num % 2 == 0)
            num /= 2;
        else
            --num;
        ++ans;
    }
    return ans;
}

// O(1) Time & O(1) Space
int numberOfSteps(int num)
{
    return num ? log2(num) + bitset<32>(num).count() : 0;
}
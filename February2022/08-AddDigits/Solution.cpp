// O(logN) Time & O(1) Space
int addDigits(int num)
{
    while (num > 9)
    {
        num = (num % 10) + (num / 10);
    }
    return num;
}

// Digit Property https://leetcode.com/problems/add-digits/discuss/1754040/C%2B%2B-Recursion-AND-Iteration-AND-O(1)-approaches.-FAST-SOLUTIONS
// O(1) Time & O(1) Space
int addDigits(int num)
{
    if (num == 0)
        return 0;
    else if (num % 9 == 0)
        return 9;
    else
        return num % 9;
}
// O(N) Time & O(1) Space
int finalValueAfterOperations(vector<string> &operations)
{
    int x = 0;
    for (auto str : operations)
    {
        if (str == "--X" || str == "X--")
            --x;
        else
            ++x;
    }
    return x;
}


// O(N) Time & O(1) Space
int finalValueAfterOperations(vector<string> &operations)
{
    int x = 0;
    for (auto &str : operations)
    {
        str[1] == '+' ? ++x : --x;
    }
    return x;
}


// O(N) Time & O(1) Space
int finalValueAfterOperations(vector<string> &operations)
{
    int x = 0;
    for (auto &str : operations)
    {
        x += ',' - str[1];
    }
    return x;
}
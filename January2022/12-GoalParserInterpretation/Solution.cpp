// O(N) Time & O(1) Space
string interpret(string command)
{
    int i = 0;
    int n = command.size();
    string ans;
    while (i < n)
    {
        if (command[i] == 'G')
        {
            ans.push_back('G');
            ++i;
        }
        else if (command[i] == '(' && i + 1 < n && command[i + 1] == ')')
        {
            ans.push_back('o');
            i += 2;
        }
        else
        {
            ans += "al";
            i += 4;
        }
    }
    return ans;
}
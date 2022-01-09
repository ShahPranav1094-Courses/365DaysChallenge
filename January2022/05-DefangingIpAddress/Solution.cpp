// O(N) Time & O(N) Space
string defangIPaddr(string address)
{
    string defangStr;
    for (auto i : address)
    {
        if (i == '.')
        {
            defangStr.push_back('[');
            defangStr.push_back('.');
            defangStr.push_back(']');
        }
        else
            defangStr.push_back(i);
    }
    return defangStr;
}
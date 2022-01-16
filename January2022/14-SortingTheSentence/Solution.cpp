// O(NlogN) Time & O(N) Space
string sortSentence(string s)
{
    map<int, string> m;
    std::stringstream ss(s);
    string temp;

    while (getline(ss, temp, ' '))
    {
        m[temp[temp.size() - 1] - '0'] = temp.substr(0, temp.size() - 1);
    }
    std::string fans;
    for (auto i : m)
        fans += i.second + ' ';
    return fans.substr(0, fans.size() - 1);
}
// O(N*N) Time & O(N) Space
int mostWordsFound(vector<string> &sentences)
{
    int maxWord = 0;
    for (const auto &str : sentences)
    {
        std::vector<string> out;
        std::stringstream ss(str);
        std::string s;
        while (std::getline(ss, s, ' '))
        {
            out.push_back(s);
        }
        if (out.size() > maxWord)
            maxWord = out.size();
    }
    return maxWord;
}
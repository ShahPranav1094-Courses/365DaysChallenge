// O(N) Time & O(1) Space
int countMatches(vector<vector<string>> &items, string ruleKey, string ruleValue)
{
    int ruleIdx = ruleKey == "type" ? 0 : ruleKey == "color" ? 1 : 2;
    int count = 0;
    for(int i=0; i < items.size(); ++i)
        if(items[i][ruleIdx] == ruleValue)
            ++count;
    return count;
}

// Use of count_if
// O(N) Time & O(1) Space
int countMatches(vector<vector<string>> &items, string ruleKey, string ruleValue)
{
    int ruleIdx = ruleKey == "type" ? 0 : ruleKey == "color" ? 1
                                                             : 2;
    return count_if(items.begin(), items.end(), [&](const auto &item)
                    { return item[ruleIdx] == ruleValue; });
}
// Recursion
// O(N) Time & O(N) Space
void combination(vector<int> &candidates, int target, vector<int> &curr, vector<vector<int>> &ans)
{
    if (candidates.empty())
        return;

    if (target == 0)
    {
        ans.push_back(curr);
        return;
    }

    if (target - candidates[0] >= 0)
    {
        curr.push_back(candidates[0]);
        combination(candidates, target - candidates[0], curr, ans);
        curr.pop_back();
        vector<int> newCandidates(candidates.begin() + 1, candidates.end());
        combination(newCandidates, target, curr, ans);
    }
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> ans;
    vector<int> curr;
    combination(candidates, target, curr, ans);
    return ans;
}

// Space Optimized
// Recursion
// O(N) Time & O(N) Space
void combination(vector<int> &candidates, int target, vector<int> &curr, vector<vector<int>> &ans)
{
    if (candidates.empty())
        return;

    if (target == 0)
    {
        ans.push_back(curr);
        return;
    }

    if (target - candidates.back() >= 0)
    {
        curr.push_back(candidates.back());
        combination(candidates, target - candidates.back(), curr, ans);
        curr.pop_back();
        int temp = candidates.back();
        candidates.pop_back();
        combination(candidates, target, curr, ans);
        candidates.push_back(temp);
    }
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    sort(candidates.begin(), candidates.end(), std::greater<>());
    vector<vector<int>> ans;
    vector<int> curr;
    combination(candidates, target, curr, ans);
    return ans;
}
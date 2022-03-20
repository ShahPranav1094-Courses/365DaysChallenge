// O(N) Time & O(1) Space
// https://leetcode.com/problems/minimum-domino-rotations-for-equal-row/discuss/901271/C%2B%2BJavaPython-One-pass-Clean-and-Concise-Strictly-O(N)
int minDominoRotations(vector<int> &tops, vector<int> &bottoms)
{
    vector<int> cntA(7, 0), cntB(7, 0), cntSame(7, 0);
    for (int i = 0; i < tops.size(); ++i)
    {
        cntA[tops[i]]++;
        cntB[bottoms[i]]++;
        if (tops[i] == bottoms[i])
            cntSame[tops[i]]++;
    }

    int ans = tops.size();
    int n = tops.size();
    for (int i = 1; i <= 6; ++i)
    {
        if (cntA[i] + cntB[i] - cntSame[i] == n)
        {
            int minAns = min(cntA[i], cntB[i]) - cntSame[i];
            ans = min(minAns, ans);
        }
    }
    return ans == n ? -1 : ans;
}
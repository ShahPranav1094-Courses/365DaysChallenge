// O(N^2) Time & O(101) Space
// https://leetcode.com/problems/3sum-with-multiplicity/discuss/181131/C%2B%2BJavaPython-O(N-%2B-101-*-101)
int threeSumMulti(vector<int> &A, int target)
{
    unordered_map<int, long> c;
    for (int a : A)
        c[a]++;
    long res = 0;
    for (auto it : c)
        for (auto it2 : c)
        {
            int i = it.first, j = it2.first, k = target - i - j;
            if (!c.count(k))
                continue;
            if (i == j && j == k)
                res += c[i] * (c[i] - 1) * (c[i] - 2) / 6;
            else if (i == j && j != k)
                res += c[i] * (c[i] - 1) / 2 * c[k];
            else if (i < j && j < k)
                res += c[i] * c[j] * c[k];
        }
    return res % int(1e9 + 7);
}


// O(N^2) Time & O(101) Space
// https://leetcode.com/problems/3sum-with-multiplicity/discuss/1123612/C%2B%2B-Super-Simple-7-line-Solution-Without-Sorting
int threeSumMulti(vector<int> &arr, int target)
{
    unordered_map<int, int> m;
    int res = 0, mod = 1e9 + 7;
    for (int i = 0; i < arr.size(); i++)
    {
        res = (res + m[target - arr[i]]) % mod;
        for (int j = 0; j < i; j++)
        {
            m[arr[i] + arr[j]]++;
        }
    }
    return res;
}


// O(N^2) Time & O(101) Space
// https://leetcode.com/problems/3sum-with-multiplicity/solution/
class Solution
{
public
    int threeSumMulti(int[] A, int target)
    {
        int MOD = 1_000_000_007;
        long ans = 0;
        Arrays.sort(A);

        for (int i = 0; i < A.length; ++i)
        {
            // We'll try to find the number of i < j < k
            // with A[j] + A[k] == T, where T = target - A[i].

            // The below is a "two sum with multiplicity".
            int T = target - A[i];
            int j = i + 1, k = A.length - 1;

            while (j < k)
            {
                // These steps proceed as in a typical two-sum.
                if (A[j] + A[k] < T)
                    j++;
                else if (A[j] + A[k] > T)
                    k--;
                else if (A[j] != A[k])
                { // We have A[j] + A[k] == T.
                    // Let's count "left": the number of A[j] == A[j+1] == A[j+2] == ...
                    // And similarly for "right".
                    int left = 1, right = 1;
                    while (j + 1 < k && A[j] == A[j + 1])
                    {
                        left++;
                        j++;
                    }
                    while (k - 1 > j && A[k] == A[k - 1])
                    {
                        right++;
                        k--;
                    }

                    ans += left * right;
                    ans %= MOD;
                    j++;
                    k--;
                }
                else
                {
                    // M = k - j + 1
                    // We contributed M * (M-1) / 2 pairs.
                    ans += (k - j + 1) * (k - j) / 2;
                    ans %= MOD;
                    break;
                }
            }
        }

        return (int)ans;
    }
}
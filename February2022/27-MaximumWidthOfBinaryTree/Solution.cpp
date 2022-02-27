// BFS
// https://leetcode.com/problems/maximum-width-of-binary-tree/discuss/1802311/C%2B%2B-oror-BFS-oror-Easy-To-Understand-oror-Full-Explanation
// O(N) Time & O(N) Space
int widthOfBinaryTree(TreeNode *root)
{
    if (root == nullptr)
        return 0;

    queue<pair<TreeNode *, int> > q;

    q.push({root, 1});

    int max_count = 1;

    while (!q.empty())
    {
        int start = q.front().second;
        int end = q.back().second;

        max_count = max(max_count, end - start + 1);

        int cz = q.size();

        for (int i = 0; i < cz; ++i)
        {
            auto curr = q.front();

            int idx = curr.second - start;

            q.pop();

            if (curr.first->left != nullptr)
                q.push({curr.first->left, (long long)2 * idx + 1});

            if (curr.first->right != nullptr)
                q.push({curr.first->right, (long long)2 * idx + 2});
        }
    }
    return max_count;
}

// O(N) Time & O(H) Space
int rangeSumBST(TreeNode *root, int low, int high)
{
    if (root == nullptr)
        return 0;
    int leftSum = rangeSumBST(root->left, low, high);
    int rightSum = rangeSumBST(root->right, low, high);
    if (root->val >= low && root->val <= high)
        return leftSum + rightSum + root->val;
    return leftSum + rightSum;
}

// O(N) Time & O(H) Space
int rangeSumBST(TreeNode *root, int low, int high)
{
    int Sum = 0;
    stack<TreeNode *> s;
    s.push(root);
    TreeNode *node = nullptr;
    while (!s.empty())
    {
        node = s.top();
        s.pop();
        if (node->val >= low && node->val <= high)
            Sum += node->val;
        if (node->val > low && node->left != nullptr)
            s.push(node->left);
        if (node->val < high && node->right != nullptr)
            s.push(node->right);
    }
    return Sum;
}
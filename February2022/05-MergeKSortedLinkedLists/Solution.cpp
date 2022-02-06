// O(N*K) Time & O(K) Space
// K is number of nodes in each list
// N total number of linkedlists
ListNode *merge(ListNode *one, ListNode *two)
{
    if (two == nullptr)
        return one;
    if (one == nullptr)
        return two;
    ListNode *temp = nullptr;
    if (two->val < one->val)
    {
        temp = two;
        temp->next = merge(one, two->next);
    }
    else
    {
        temp = one;
        temp->next = merge(one->next, two);
    }
    return temp;
}

ListNode *mergeKLists(vector<ListNode *> &lists)
{
    if (lists.empty())
        return nullptr;
    for (int i = lists.size() - 1; i > 0; --i)
    {
        if (lists[i] == nullptr)
            continue;
        lists[i - 1] = merge(lists[i - 1], lists[i]);
    }
    return lists[0];
}

// Optimized
// O(KlogN) Time & O(K) Space
// K is number of nodes in each list
// N total number of linkedlists
ListNode *merge(ListNode *one, ListNode *two)
{
    if (two == nullptr)
        return one;
    if (one == nullptr)
        return two;
    ListNode *temp = nullptr;
    if (two->val < one->val)
    {
        temp = two;
        temp->next = merge(one, two->next);
    }
    else
    {
        temp = one;
        temp->next = merge(one->next, two);
    }
    return temp;
}

ListNode *mergeKLists(vector<ListNode *> &lists)
{
    if (lists.empty())
        return nullptr;
    int len = lists.size();
    while (len > 1)
    {
        for (int i = 0; i < len / 2; ++i)
        {
            lists[i] = merge(lists[i], lists[len - 1 - i]);
        }
        len = (len + 1) / 2;
    }
    return lists.front();
}
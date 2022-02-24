// O(NlogN) Time & O(1) Space
ListNode *sortList(ListNode *head)
{
    if (!head || !head->next)
        return head;
    ListNode *mid = getMid(head);
    ListNode *left = sortList(head);
    ListNode *right = sortList(mid);
    return merge(left, right);
}

ListNode *merge(ListNode *list1, ListNode *list2)
{
    if (list2 == nullptr)
        return list1;
    if (list1 == nullptr)
        return list2;

    if (list1->val < list2->val)
    {
        list1->next = merge(list1->next, list2);
        return list1;
    }
    else
    {
        list2->next = merge(list1, list2->next);
        return list2;
    }
}

ListNode *getMid(ListNode *head)
{
    ListNode *midPrev = head;
    while (head && head->next)
    {
        head = head->next->next;
        if (head)
            midPrev = midPrev->next;
    }
    ListNode *mid = midPrev->next;
    midPrev->next = nullptr;
    return mid;
}
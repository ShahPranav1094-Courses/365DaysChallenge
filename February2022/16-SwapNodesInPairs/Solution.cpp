// O(N) Time & O(1) Space
ListNode *swapPairs(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;
    ListNode *p, *q, *r = head, *s = head;
    bool isHeadSwapped = false;
    while (r != nullptr)
    {
        if (r->next == nullptr)
            return head;
        else
        {
            p = r->next;
            q = p->next;
            p->next = r;
            r->next = q;
            if (isHeadSwapped)
                s->next = p;
            else
            {
                head = p;
                isHeadSwapped = true;
            }
            s = r;
            r = r->next;
        }
    }
    return head;
}


// Recursion
// O(N) Time & O(N) Space
ListNode *swapNodes(ListNode *node1, ListNode *node2)
{
    if (node2 == nullptr)
        return node1;
    ListNode *next = node2->next;
    node2->next = node1;
    node1->next = next == nullptr ? next : swapNodes(next, next->next);
    return node2;
}

ListNode *swapPairs(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;
    return swapNodes(head, head->next);
}
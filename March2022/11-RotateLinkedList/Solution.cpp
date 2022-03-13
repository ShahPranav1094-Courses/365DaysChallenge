// O(N) Time & O(1) Space
ListNode *rotateRight(ListNode *head, int k)
{
    if (head == nullptr)
        return head;

    ListNode *slow = head, *fast = head;
    ListNode *curr = head;
    int sz = 0;
    while (curr)
    {
        curr = curr->next;
        ++sz;
    }

    k = k % sz;
    if (k == 0)
        return head;

    while (fast && k--)
    {
        fast = fast->next;
    }

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next;
    }

    fast->next = head;
    head = slow->next;
    slow->next = nullptr;
    return head;
}
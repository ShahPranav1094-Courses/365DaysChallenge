// O(N) Time & O(1) Space
bool hasCycle(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
        return false;

    ListNode *fast = head, *slow = head;

    do
    {
        fast = fast->next;
        slow = slow->next;
        if (fast)
            fast = fast->next;
    } while (fast != nullptr && slow != nullptr && slow != fast);
    return slow == fast;
}
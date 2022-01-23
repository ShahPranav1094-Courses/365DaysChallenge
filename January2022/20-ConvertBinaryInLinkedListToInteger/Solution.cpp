// O(N) Time & O(1) Space
// Reverse
int getDecimalValue(ListNode *head)
{
    if (head == nullptr)
        return 0;
    ListNode *prev = nullptr, *next = nullptr, *curr = head;
    while (curr != nullptr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    int ans = prev->val;
    prev = prev->next;
    int i = 2;
    while (prev != nullptr)
    {
        ans += prev->val * i;
        i = i * 2;
        prev = prev->next;
    }
    return ans;
}

// O(N) Time & O(1) Space
int getDecimalValue(ListNode *head)
{
    int res = 0;
    while (head != nullptr)
    {
        res = res * 2 + head->val;
        head = head->next;
    }
    return res;
}

// O(N) Time & O(1) Space
// Left shift
int getDecimalValue(ListNode *head)
{
    int res = 0;
    while (head != nullptr)
    {
        res = res << 1 | head->val;
        head = head->next;
    }
    return res;
}
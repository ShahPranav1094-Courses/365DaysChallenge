// O(N) Time & O(1) Space
Node *copyRandomList(Node *head)
{
    if (head == nullptr)
        return nullptr;

    Node *curr = head;
    while (curr)
    {
        Node *copy = new Node(curr->val);
        copy->next = curr->next;
        curr->next = copy;
        curr = curr->next->next;
    }

    curr = head;
    while (curr)
    {
        if (curr->next)
            curr->next->random = curr->random ? curr->random->next : curr->random;
        curr = curr->next ? curr->next->next : curr->next;
    }

    Node *copyHead = head->next;
    curr = head;
    Node *copy = head->next;
    while (curr)
    {
        curr->next = curr->next ? curr->next->next : curr->next;
        copy->next = copy->next ? copy->next->next : copy->next;

        curr = curr->next;
        copy = copy->next;
    }
    return copyHead;
}
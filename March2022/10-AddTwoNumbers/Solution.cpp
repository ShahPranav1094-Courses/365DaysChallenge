// O(N) Time & O(1) Space
class Solution
{
public:
    ListNode *last = nullptr;

    ListNode *AddToResult(ListNode *result, int val)
    {
        if (result == nullptr)
        {
            result = new ListNode(val);
            last = result;
            return result;
        }
        ListNode *temp = new ListNode(val);
        last->next = temp;
        last = last->next;
        return result;
    }

    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int carry = 0;
        int temp = 0;
        ListNode *result = nullptr;
        while (l1 != nullptr && l2 != nullptr)
        {
            temp = (l1->val + l2->val + carry) / 10 ? ((l1->val + l2->val + carry) / 10) % 10 : 0;
            result = AddToResult(result, (l1->val + l2->val + carry) % 10);
            carry = temp;
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1 != nullptr)
        {
            temp = (l1->val + carry) / 10 ? ((l1->val + carry) / 10) % 10 : 0;
            result = AddToResult(result, (l1->val + carry) % 10);
            carry = temp;
            l1 = l1->next;
        }
        while (l2 != nullptr)
        {
            temp = (l2->val + carry) / 10 ? ((l2->val + carry) / 10) % 10 : 0;
            result = AddToResult(result, (l2->val + carry) % 10);
            carry = temp;
            l2 = l2->next;
        }
        if (carry)
            result = AddToResult(result, carry);
        return result;
    }
};
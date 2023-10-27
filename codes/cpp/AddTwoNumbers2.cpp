class Solution
{
    public:
        ListNode* reverseLL(ListNode *head)
        {
            ListNode *curr = head;
            ListNode *prev = NULL;
            ListNode *forward = NULL;

            while (curr)
            {
                forward = curr->next;
                curr->next = prev;
                prev = curr;
                curr = forward;
            }
            return prev;
        }
    ListNode* insert_tail(ListNode *head, int val)
    {
        ListNode *ptr = new ListNode(val);
        ListNode *temp = head;
        if (head == NULL)
        {
            head = ptr;
            return head;
        }
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = ptr;
        return head;
    }
    ListNode* adding(ListNode *l1, ListNode *l2)
    {
        ListNode *ans = NULL;
        int carry = 0;
        int sum = l1->val + l2->val;
        while (l1 || l2 || carry)
        {
            int val1 = 0, val2 = 0;
            if (l1)
                val1 = l1->val;
            if (l2)
                val2 = l2->val;
            sum = val1 + val2 + carry;

            ans = insert_tail(ans, sum % 10);
            carry = sum / 10;

            if (l1)
                l1 = l1->next;
            if (l2)
                l2 = l2->next;
        }
        return ans;
    }
    ListNode* addTwoNumbers(ListNode *l1, ListNode *l2)
    {
       	//step 1
        l1 = reverseLL(l1);
        l2 = reverseLL(l2);

       	//step 2
        ListNode *ans = adding(l1, l2);

       	//step 3
        ans = reverseLL(ans);
        return ans;
    }
    
};
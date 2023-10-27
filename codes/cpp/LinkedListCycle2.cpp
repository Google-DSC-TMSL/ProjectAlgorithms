/**
 *Definition for singly-linked list.
 *struct ListNode {
 *int val;
 *ListNode * next;
 *ListNode(int x) : val(x), next(NULL) {}
 *};
 */
class Solution
{
    public:
        ListNode* FloydCycle(ListNode *head)
        {
            if (head == NULL)
                return NULL;
            ListNode *slow = head;
            ListNode *fast = head;
            while (fast)
            {
                if (fast->next == NULL)
                    return NULL;
                fast = fast->next->next;
                slow = slow->next;
                if (fast == slow)
                    return slow;
            }

            return NULL;
        }
    ListNode* detectCycle(ListNode *head)
    {

        ListNode *intersection = FloydCycle(head);
    
        if (intersection == NULL)
            return NULL;
        ListNode *slow = head;
        while (slow != intersection)
        {
            slow = slow->next;
            intersection = intersection->next;
        }
        return slow;
    }
};
/**
 *Definition for singly-linked list.
 *struct ListNode {
 *   int val;
 *   ListNode * next;
 *   ListNode() : val(0), next(nullptr) {}
 *   ListNode(int x) : val(x), next(nullptr) {}
 *   ListNode(int x, ListNode *next) : val(x), next(next) {}
 *};
 */
class Solution
{
    public:
        ListNode* oddEvenList(ListNode *head)
        {
            if (head == NULL || head->next == NULL || head->next->next == NULL) return head;
            ListNode *odd = NULL;
            ListNode *o = NULL;
            ListNode *even = NULL;
            ListNode *e = NULL;

            int i = 1;
            while (head)
            {
                if (i % 2 == 0)
                {
                    if (even == NULL)
                    {
                        even = head;
                        e = head;
                    }
                    else
                    {
                        e->next = head;
                        e = e->next;
                    }
                }
                else
                {
                    if (odd == NULL)
                    {
                        odd = head;
                        o = head;
                    }
                    else
                    {
                        o->next = head;
                        o = o->next;
                    }
                }
                head = head->next;
                i++;
            }
            if (odd)
                o->next = even;
            if (even)
                e->next = NULL;
            if (odd == NULL) return even;
            return odd;
        }
};
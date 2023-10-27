/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution
{
    public:
        Node* insert_tail(Node *head, int val)
        {
            Node *ptr = new Node(val);
            Node *temp = head;
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
    Node* copyRandomList(Node *head)
    {
       	//step 1: create clone linked list
        Node *clone = NULL;
        Node *temp = head;
        while (temp)
        {
            clone = insert_tail(clone, temp->val);
            temp = temp->next;
        }
       	//step 2: create map
        temp = head;
        Node *temp1 = clone;
        unordered_map<Node*, Node*> mapping;
        while (temp)
        {
            mapping[temp] = temp1;
            temp = temp->next;
            temp1 = temp1->next;
        }

        temp1 = clone;
        temp = head;
        while (temp)
        {
            temp1->random = mapping[temp->random];
            temp = temp->next;
            temp1 = temp1->next;
        }

        return clone;
    }
};
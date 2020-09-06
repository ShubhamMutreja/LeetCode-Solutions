/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution 
{
public:
    ListNode *detectCycle(ListNode *head) 
    {
        if(head == NULL)
        {
            return NULL;
        }
        ListNode *fast = head;
        ListNode *slow = head;
        ListNode *g;
        while(fast!= NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            if(fast == slow)
            {
                g = head;
                while(slow != g)
                {
                    slow = slow->next;
                    g = g->next;
                }
                return slow;
            }
        
        }
        return NULL;
    }
    
};


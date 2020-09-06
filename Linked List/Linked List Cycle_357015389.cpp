/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL || head->next == NULL )
        {
            return false;
        }
        ListNode *slow = head;
        ListNode *fast = head;
        
        while(fast!=NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            
            if(fast == slow)
            {
                break;
            }
        }
        return fast == slow ? true:false;
    }
};

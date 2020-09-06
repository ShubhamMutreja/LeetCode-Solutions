/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head == NULL)
            return head;
        ListNode* prev = head;
        ListNode* curr = head;
        while(curr != NULL)
        {
            if(curr->val == val)
            {
                if(curr == head)
                {
                    head = curr->next;
                    prev = head;
                    curr = prev;
                }
                else
                {
                    prev->next = curr->next;
                    curr->next = NULL;
                    curr = prev->next;
                }
            }
            else
            {
                prev = curr;
                curr = curr->next;
            }
            
        }
        
        return head;
        
    }
};

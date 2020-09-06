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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == NULL || head->next == NULL)
            return NULL;
        ListNode* c1 = head; ListNode* c2 = head;
        while(n--)
            c2 = c2->next;
        
        if(c2 == NULL)
            return head->next;
        while(c2->next != NULL)
        {
            c1 = c1->next;
            c2 = c2->next;
        }
        ListNode* rnode = c1->next;
        c1->next = rnode->next;
        rnode->next = NULL;
        
        return head;
            
    }
};

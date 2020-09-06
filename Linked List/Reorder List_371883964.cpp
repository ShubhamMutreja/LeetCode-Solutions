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
    ListNode* mid(ListNode* node)
    {
        if(node == NULL || node->next == NULL)
            return node;
        
        ListNode* slow=node,*fast = node;
        while(fast->next != NULL && fast->next->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* reverse(ListNode* node)
    {
        if(node == NULL || node->next == NULL)
            return node;
        ListNode* curr = node;
        ListNode* prev = NULL;
        
        while(curr != NULL)
        {
            ListNode* forw = curr->next;
            curr->next = prev;
            
            prev = curr;
            curr = forw;
        }
        return prev;
        
    }
    void reorderList(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return;
        ListNode* m = mid(head);
        ListNode* nhead = m->next;
        
        m->next = NULL;
        
        nhead = reverse(nhead);
        ListNode* c1 = head, *c2 = nhead;
        
        while(c1 != NULL && c2 != NULL)
        {
            ListNode* f1 = c1->next, *f2 = c2->next;
            c1->next = c2;
            c2->next = f1;
            
            c1 = f1; c2 = f2;
        }
        
    }
};

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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL)
            return head;
        ListNode* p = head;
        ListNode* q = head->next;
        ListNode* head2 = q;
        
        while(q)
        {
            if(q->next)
            {
                p->next = q->next;
                p = q->next;
                q->next = p->next;
                q = p->next;
            }
            else
            {
                break;
            }
        }
        p->next = head2;
        return head;
        
    }
};

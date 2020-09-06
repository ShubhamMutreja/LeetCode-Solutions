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
    ListNode* merge2(ListNode* p, ListNode* q)
    {
        if(p == NULL && q == NULL)
            return p==NULL ? q : p;
        
        ListNode* head = new ListNode(-1);
        ListNode* prev = head;
        
        ListNode* c1 = p, *c2 = q;
        while(c1 != NULL && c2 != NULL)
        {
            if(c1->val <= c2->val)
            {
                prev->next = c1;
                prev = c1;
                c1 = c1->next;
            }
            else
            {
                prev->next = c2;
                prev = c2;
                c2 = c2->next;
            }
        }
        if(c1 != NULL)
            prev->next = c1;
        else
            prev->next = c2;
        return head->next;
    }
    ListNode* merge_recur(vector<ListNode*>& lists, int i, int j)
    {
        if(i==j)
            return lists[i];
        
        int m = (i+j)/2;
        
        ListNode* l1 = merge_recur(lists,i,m);
        ListNode* l2 = merge_recur(lists,m+1,j);
        ListNode* head = merge2(l1,l2);
        
        return head;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0)
            return NULL;
        return merge_recur(lists,0,lists.size()-1);
    }
};

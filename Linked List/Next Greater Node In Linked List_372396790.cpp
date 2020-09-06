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
    vector<int> nextLargerNodes(ListNode* head) {
        if(head == NULL)
            return {};
        if(head->next == NULL)
            return {0};
        
        ListNode* slow = head, *fast = head->next;
        vector<int> v;
        while(slow != NULL)
        {
            if(fast->val > slow->val)
            {
                v.push_back(fast->val);
                slow = slow->next;
                fast = slow;
            }
            else
            {
                fast = fast->next;
            }
            
            if(fast == NULL)
            {
                v.push_back(0);
                fast = slow->next;
                slow = slow->next;
            }
        }
        return v;
    }
};

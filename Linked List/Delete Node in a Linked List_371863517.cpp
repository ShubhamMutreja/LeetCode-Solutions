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
    void deleteNode(ListNode* node) {
        ListNode * after = node->next;
        if(!after);
        else
        {
            node->val = after->val;
            node->next = after->next;
        }
        delete after;
    }
};

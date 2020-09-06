class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL)
        {
            return NULL;
        }
        ListNode *node = headA;
        while(node->next != NULL)
        {
            node = node->next;
        }
        node->next = headB;
                
        ListNode *fast = headA;
        ListNode *slow = headA;
        
        while(fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            if(fast == NULL || fast->next == NULL)
            {
                node->next = NULL;
                return NULL;
            }
            if(fast == slow)
            {
                break;
            }
        }
        if(slow != fast)
        {
            return NULL;
        }
        slow = headA;
        while(slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
        node->next = NULL;
        return fast;
    }
};

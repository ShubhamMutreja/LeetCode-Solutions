class Solution {
public:
    ListNode* mid(ListNode* head)
    {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode * fast = head;
        ListNode * slow = head;
        
        while(fast->next != NULL && fast->next->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* reverse(ListNode* head)
    {
        if(head == NULL || head->next == NULL)
            return head;
        
        ListNode* curr = head;
        ListNode* prev = NULL;
        
        while(curr != NULL){
            ListNode* forw = curr->next;
            curr->next = prev;
            
            prev = curr;
            curr = forw;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return true;
        ListNode* midd = mid(head);
        ListNode* nhead = midd->next;
        bool res = true;
        midd->next = NULL;
        
        nhead = reverse(nhead);
        
        ListNode* c1 = head, * c2 =nhead;
        while(c1 != NULL && c2 != NULL)
        {
            if(c1->val != c2->val)
            {
                res = false;
                break;
            }
            c1 = c1->next; c2 = c2->next;
        }
        nhead = reverse(nhead);
        midd->next = nhead;
        return res;
        
    }
};

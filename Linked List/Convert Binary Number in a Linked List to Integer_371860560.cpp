class Solution {
public:
    int lent(ListNode* n)
    {
        if(n== NULL)
            return 0;
        int le = 0;
        while(n != NULL)
        {
            le++;
            n = n->next;
        }
        return le;
    }  
    int getDecimalValue(ListNode* head) {
        int l = lent(head);
        int out=0;
        while(l--)
        {
            if(head->val == 1)
                out += (int)(pow(2,l) + 0.5);
            head = head->next;
        }
        return out;
    }
};

class Solution 
{
    ListNode * oH = NULL;
    ListNode * oT = NULL;
    ListNode * tH = NULL;
    ListNode * tT = NULL;
public:
    void addFirst(ListNode *node)
    {
        if(tT == NULL)
        {
            tH=node;
            tT=node;
        }
        else
        {
            node->next = tH;
            tH = node;
        }
        //cout<<"add";
    }
    ListNode* reverseBetween(ListNode* head, int m, int n) 
    {
        if(head == NULL || head->next == NULL || m==n)
        {
            return head;
        }
        int i=1;
        ListNode *curr = head;
        ListNode *prev = NULL;
        
        while(curr !=NULL)
        {
            while(i<=n && i>=m)
            {
                ListNode *rnode = curr;
                curr = curr->next;
                rnode->next = NULL;
                addFirst(rnode);
                i++;
            }
            if(i>n)
            {
                if(prev != NULL)
                {
                    prev->next = tH;
                    tT->next = curr;
                }
                else
                {
                    tT->next = curr;
                    head = tH;
                }
                break;
            }
            prev = curr;
            curr = curr->next;
            i++;
        }
        return head;
    }
};

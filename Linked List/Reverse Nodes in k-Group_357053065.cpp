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
class Solution 
{
    ListNode * oH = NULL;
    ListNode * oT = NULL;
    ListNode * tH = NULL;
    ListNode * tT = NULL;
public:
    int lenll(ListNode *head)
    {
        if(head == NULL)
        {
            return 0;
        }
        int len = 1;
        while(head->next != NULL)
        {
            head = head->next;
            len++;
        }
        return len;
    }
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
    }
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        if(head==NULL || head->next == NULL || k<=1)
        {
            return head;
        }
        ListNode * curr = head;
        int len = lenll(head);
        while(curr!=NULL && len>=k)
        {
            int temp = k;
            while(temp--)
            {
                ListNode *rnode = curr;
                curr = curr->next;
                rnode->next = NULL;
                addFirst(rnode);
            }
            if(oH == NULL)
            {
                oH = tH;
                oT = tT;
            }
            else
            {
                oT->next = tH;
                oT = tT;
            }
            tH = NULL;
            tT= NULL;
            
            len-=k;
        }
        oT->next = curr;
        return oH;
    }
};

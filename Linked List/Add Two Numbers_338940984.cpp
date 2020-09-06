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
 ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        int qot = 0; // Quotient to deal with carry forward after adding 2 digits from l1 and l2
        int rem=0;  // Remainder or after adding up two digits from l1 and l2. 
        int sum; // Sum of 2 digits from l1 and l2
        ListNode *resultHead = NULL; // Pointer that remains at the Head of the Result List
        ListNode *resultTail = NULL;  // Pointer that point that moves ahead after adding up digists in l1 and l2. 
            It is always the tail of the result list. 
        
        while(l1 != NULL && l2 != NULL)  // Run this loop till both the list are not NULL
        {
            sum = l1->val + l2->val + qot;
            rem = sum%10;
            qot = sum/10;
            
            ListNode *temp = new ListNode(rem);
            if(resultHead == NULL) // First Node of the result List
            {
                resultHead = temp;
                resultTail = temp;
            }
            else
            {
                resultTail->next = temp; // Added the
                resultTail = temp;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        
        while(l1 != NULL) // When Number of digits in L1 is more than number of digits in L2
        {
            sum = l1->val + qot;
            rem = sum%10;
            qot = sum/10;
            ListNode *temp = new ListNode(rem);
            if(resultHead == NULL)
            {
                resultHead = temp;
                resultTail = temp;
            }
            else
            {
                resultTail->next = temp;
                resultTail = temp;
            }    
            l1 = l1->next;
        }
        
        while(l2 != NULL) // When Number of digits in L2 is more than number of digits in L1
        {
            sum = l2->val + qot;
            rem = sum%10;
            qot = sum/10;
            ListNode *temp = new ListNode(rem);
            if(resultHead == NULL)
            {
                resultHead = temp;
                resultTail = temp;
            }
            else
            {
                resultTail->next = temp;
                resultTail = temp;
            }  
            l2 = l2->next;
        }
        if(qot != 0) // If any carry forward still exists add that as a new node
        {
            ListNode *temp = new ListNode(qot);
            resultTail->next = temp;        
        }
        return resultHead;
    }
};

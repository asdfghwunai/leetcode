/*
 Given a linked list, return the node where the cycle begins. If there is no cycle, returnnull.

Follow up:
Can you solve it without using extra space? 

*/

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
    ListNode *detectCycle(ListNode *head) {
        ListNode *pre=head;
        ListNode *cur=head;
        if(head==NULL || head->next==NULL)
            return NULL;
        
       
        while(cur&&cur->next)
        {
           cur=cur->next->next;
           pre=pre->next;
           if(cur==pre)      
           {
               ListNode *p=head;
               while(p!=cur)   //用到一个规律
               {
                   cur=cur->next;
                   p=p->next;
               }
               return p;
           }
            
        }
        return NULL;
    }
};

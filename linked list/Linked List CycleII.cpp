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
        
       //如果结点个数是偶数个的话，slow指向中间两个元素的右边那个 比如1->2->NULL,slow是2，fast是null，和sort list不太一样
       //我知道为啥slow和cur一开始都是head了，因为要满足slow走s步，fast走2s步，但是这个返回的中点不是标准中点
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

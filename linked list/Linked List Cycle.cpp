 /*
 Given a linked list, determine if it has a cycle in it.

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
    bool hasCycle(ListNode *head) {
        ListNode *pre=head;
        ListNode *cur=head;
        //方法还是快慢指针，下面循环参考了求链表中值
        
        int i=0,j=0;
        while(cur)
        {
            
            if(i/2>j)   //这里2,3都行，只要走得快就行
            {
                j++;
                pre=pre->next;
            }
            if(cur==pre&&i!=0)   //跳过第一次判断，早晚会追上的
                return 1;
            
            i++;
            cur=cur->next;
        }
        
        return 0;
    }
};

//-----上面的方法对链表环II没辙了,你可以推一下
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==NULL||head->next==NULL)
            return 0;
        ListNode *pre=head;
        ListNode *cur=head;
        
        while(cur&&cur->next)   //醉了，判断cur是为了cur->next，判断cur->next是为了cur->next->next
        {
            pre=pre->next;
            cur=cur->next->next;
            if(pre==cur)
                return 1;
            
        }
        
        return 0;
    }
};

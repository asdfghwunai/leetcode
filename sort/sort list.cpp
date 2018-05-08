//Sort a linked list in O(n log n) time using constant space complexity.

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
    /*
    ListNode *merge(ListNode *l1,ListNode *l2)
    {
        ListNode *head=NULL;
        if(l1==NULL)    //俩终止条件
        {
            head=l2;
            return head;
        }    
        if(l2==NULL)
        {
            head=l1;
            return head;
        }
        
        if(l1->val<=l2->val)   //进入下层递归
        {
            head=l1;
            head->next=merge(l1->next,l2);  
        }
        else
        {
            head=l2;
            head->next=merge(l1,l2->next);
        }
        return head;           //平常的返回
    }
    */
    
    ListNode *merge2(ListNode *l1,ListNode *l2)   ////扩展：之所以可以用一维指针，因为里面操作的是l1->next,并没有改l1和l2本身的值
    {
        ListNode *head=NULL;
        if(l1==NULL)    //俩终止条件
        {
            head=l2;
            return head;
        }    
        if(l2==NULL)
        {
            head=l1;
            return head;
        }
        
        //融合像归并排序中数组融合那样就行了,还是挺简单的
        ListNode *dummy=new ListNode(-1);
        ListNode *p=dummy;
        ListNode *p1=l1;
        ListNode *p2=l2;
        
        while(p1&&p2)
        {
            if(p1->val<=p2->val)
            {
                p->next=p1;  //连起来
                p1=p1->next;  //进到下一位
                p=p->next;
            }
            else
            {
                p->next=p2;
                p2=p2->next;
                p=p->next;
            }
        }
        if(p1)   //谁完就连对方
          p->next=p1;    //这里当时写反了
        else if(p2)
          p->next=p2;
        
        return dummy->next;           //平常的返回
    }
    
    
    
    ListNode *sortList(ListNode *head) {
        if(head==NULL||head->next==NULL)
            return head;   //不用排了
        
        ListNode *slow=head;
        ListNode *fast=head;
        while(fast!=NULL&&fast->next!=NULL)   //找到链表中间
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        /*
        ListNode *last1=slow;     //分段
        ListNode *first1=slow->next;
        slow->next=NULL;
        */
        
        fast=slow->next;
        slow->next=NULL;
        
        ListNode *p1=sortList(head);
        ListNode *p2=sortList(fast);
        ListNode *tou=merge2(p1,p2);
        
        return tou;
    }
};

/*


Merge two sorted linked lists and return it as a new list. 
The new list should be made by splicing together the nodes of the first two lists. 

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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        //方法  ---先自顶向下,然后自顶向上递归解决，这其实就是归并排序中融合俩数组的地方，数组融合是迭代解决，这里只能递归吗
        ListNode *head=NULL;
        if(l1==NULL)
            return l2;
        if(l2==NULL)
            return l1;    //俩终止条件
        
        if(l1->val<=l2->val)
        {
            head=l1;
            head->next=mergeTwoLists(l1->next,l2);  //进下层递归
        }
        else
        {
            head=l2;
            head->next=mergeTwoLists(l1,l2->next);
        }
        return head;   //普通返回
        
        
    }
};

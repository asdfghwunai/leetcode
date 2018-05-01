/*
 Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array A =[1,1,1,2,2,3],

Your function should return length =5, and A is now[1,1,2,2,3]. 
*/

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        
        //方法--快慢指针
        if(n==0)
            return 0;
        
        bool flag=0;   //flag也可替换成num，这样num<2时可以接着赋值，最后可满足需要重复次数更多的情况
        int index=0;
        for(int i=1;i<n;i++)   //遍历用
        {
            if(A[index]==A[i])
            {
                if(flag==0)   //只增一次index
                {
                    A[index+1]=A[i];     //这句话不能少，赋值都是这样赋的
                    index++;     //只有这句没上句是不对的
                    flag=1;
                }
            }
            else
            {
                A[index+1]=A[i];   //赋值
                index++;
                flag=0;
            }
        }
        return index+1;
    }
};

/*
 Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e.,0 1 2 4 5 6 7might become4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array. 
*/

class Solution {
public:
    int search(int A[], int n, int target) {
         int first=0;
        int last=n-1;
        while(first<=last)
        {
            int mid=(first+last)/2;
            if(A[mid]==target)
                return mid;
            else
            {
                
                if(A[first]<A[mid])  //左边有序
                {
                    if(A[first]<=target&&target<A[mid]) //确定目标在左边
                        last=mid-1;
                    else
                        first=mid+1;
                }
                else if(A[first]>A[mid])  //右边有序
                {
                    if(A[mid]<target&&target<=A[last]) //确定目标在右边
                        first=mid+1;
                    else
                        last=mid-1;
                }
                else if(A[first]==A[mid])  //不能判断
                    first++; 
                //一定要加上else,不然有的情况会重复执行，也不符合逻辑
            }
        }
        return -1;
    }
};

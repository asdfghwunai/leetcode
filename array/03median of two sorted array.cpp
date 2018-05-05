/*
There are two sorted arrays A and B of size m and n respectively. Find the median of the two sorted arrays. 
The overall run time complexity should be O(log (m+n)). 
*/


class Solution {
public:
    double findKth(int A[], int m, int B[], int n,int k)
    {
        if(m==0)
            return B[k-1];  //m和n是当前长度
        if(n==0)
            return A[k-1];
        
        if(k==1)
            return  min(*A,*B);
        if(m>n)  //颠倒一下，保证第一个数组长度较小
            return findKth(B, n, A, m,k);
        
        //k!=1就要根据情况舍弃
        int jiangeA=min(k/2,m);  //本次要舍弃的数目
        int jiangeB=k-jiangeA;
        
        int Atemp=A[jiangeA-1];  //如果k是第5大,会舍弃2个，还有3个要判断
        int Btemp=B[jiangeB-1];   //如果k是第4大,会舍弃2个，还有2个要判断
        if(Atemp==Btemp)
            return Atemp;
        else if(Atemp>Btemp)
            return findKth(A,m,B+jiangeB,n-jiangeB,k-jiangeB);  //找第k-jiange个数
        else
            return findKth(A+jiangeA,m-jiangeA,B,n,k-jiangeA);
        
    }
    
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int k=(m+n);  //k为7找第4大，k为8找第4和第5大
        if(k%2==0)
           return (findKth(A,m,B,n,k/2)+findKth(A,m,B,n,k/2+1))/2;
        else
            return findKth(A,m,B,n,k/2+1); //为奇数就返回中间值，k是第几大，取值范围>=1
    }
};

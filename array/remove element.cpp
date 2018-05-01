 /*
 Given an array and a value, remove all instances of that value in place and return the new length.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.
*/

class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        //方法 双指针,不通过
        int i=0;
        int j=0;
        int tail=0;
        for(j=0;j<n;j++) //遍历
        {
            if(A[j]==elem)
                continue;
            A[i++]=A[j];
        }
        return i;  //i-1是最后一个有效元素的下标,人家要长度

    }
};

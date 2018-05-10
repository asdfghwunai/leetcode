/*
'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "a*") → true
isMatch("aa", ".*") → true
isMatch("ab", ".*") → true
isMatch("aab", "c*a*b") → true

*/

//方法---首先确定用递归，然后要分析好转移条件
class Solution {
public:
    bool isMatch(const char *s, const char *p) {
      if(*s!='\0'&&*p=='\0')
          return false;         //终止条件1
      if(*s=='\0'&&*p=='\0')
          return true;          //终止条件2
        
      if(*(p+1)=='*')       //大情况1
      {
          while(*s==*p||(*s!='\0'&&*p=='.'))
          {
              if(isMatch(s,p+2))   //---*等于1到n的情况
                  return true;      
              s++;      //找到第一个不匹配的
          }
          //if(*s=='\0')
          //    return true;    //这三句错的，s='\0'还要p='\0'才行
          //else 
              return isMatch(s,p+2);   //*等于0情况
      }
      else          //大情况2
      {
          if(*s==*p||(*s!='\0'&&*p=='.'))
              return isMatch(s+1,p+1);
          else
              return false;
      }
            
    }
};

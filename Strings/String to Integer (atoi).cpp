/*
Leetcode Link               : https://leetcode.com/problems/string-to-integer-atoi/
Leetcode difficulty         : Medium
Leetcode Related Topic      : String
*/

//------------------------------Solution - in - C++ -----------------------------------------------------------

//Approach 1: Brute Approach
//T.C       : O(n) — 
//S.C       : O(1) — 
class Solution {
public:
    int myAtoi(string s) {
        int i=0;
        int n=s.length();
        int sign=1;
        long long result=0;
        
        
        //skip the spaces
        while(i<n && s[i]==' '){
            i++;
        }
            
        //check sign
        if(i<n && s[i]=='+' || s[i]=='-'){
            sign=(s[i]=='-'?-1:1);
            i++;
        }
        //convrt char to int
        while(i<n && isdigit(s[i])){
                int digit=s[i]-'0';
            
            //check overfloe before multiplying by 10
            if(result>(INT_MAX-digit)/10){
                return sign==1?INT_MAX:INT_MIN;
            }    
            result=result*10+digit;
            i++;
        }
        return sign*result;
    }
};
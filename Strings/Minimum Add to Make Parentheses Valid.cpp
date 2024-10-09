/*
Leetcode Link           : https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/
Leetcode difficulty     : Medium
Leetcode Related Topic  : String, Stack, Greedy
Medium Article Link	    : 
*/

//------------------------------Solution - in - C++ -----------------------------------------------------------

//Approach 1: Greedy Count Approach
//T.C       : O(n)
//S.C       : O(1)
//-----------------------------------------------------------------------------------------------------------------
class Solution {
public:
    int minAddToMakeValid(string s) {
        int open=0, close=0;
        for(auto c:s){
            if(c=='('){
                open++;
            }else{
                if(open>0){
                    open--;
                }else{
                    close++;
                }
            }
        }
        return abs(open+close);
    }
};
//-----------------------------------------------------------------------------------------------------------------
/*
Leetcode Link           : https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-string-balanced/
Leetcode difficulty     : Easy
Leetcode Related Topic  : Stack, Two-Pointer, string, Greedy
Medium Article Link	    : 
*/

//------------------------------Solution - in - C++ -----------------------------------------------------------

//Approach 1: Greedy Approach with Counting
//T.C       : O(n)
//S.C       : O(1)
//-----------------------------------------------------------------------------------------------------------------
class Solution {
public:
    int minSwaps(string s) {
        stack <char> st;
        
        for(auto c:s){
            if(c=='['){
                st.push(c);
            }else if(!st.empty()){
                st.pop();
            }
        }
        return (st.size()+1)/2;
    }
};
//-----------------------------------------------------------------------------------------------------------------
//Approach 2: Stack-Based Approach
//T.C       : O(n)
//S.C       : O(n)
//-----------------------------------------------------------------------------------------------------------------
class Solution {
public:
    int minSwaps(string s) {
        int balance=0, minBalance=0;
        
        for(auto c:s){
            if(c=='['){
                balance++;
            }else{
                balance--;
            }
            minBalance=min(minBalance, balance);
        }
        return (-minBalance+1)/2;
    }
};
//-----------------------------------------------------------------------------------------------------------------

/*
Leetcode Link           : https://leetcode.com/problems/permutation-in-string/
Leetcode difficulty     : Medium
Leetcode Related Topic  : Hash Tale, Two Pointers, String, Sliding window
Intuition       	    : Generate all substrings of length len(s1) from s2, sort them, and compare them with the sorted version of s1. 
                          If any sorted substring matches the sorted version of s1, return true.
*/

//------------------------------Solution - in - C++ -----------------------------------------------------------

//Approach 1: Sorting and Checking All Substrings (Brute Force)
//T.C       : O(nlogn)
//S.C       : O(n)
//--------------------------------------------------------------------------------------------------------------
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        int n=s1.length();
        int m=s2.length();
        string sorted_s1=s1;
        
        sort(s1.begin(), s1.end());
        
        for(int i=0; i<=m-n; i++){
            string temp=s2.substr(i, n);
            
            sort(temp.begin(), temp.end());
            
            if(temp==s1){
                return true;
            }
        }
        return false;
        
    }
};
//--------------------------------------------------------------------------------------------------------------
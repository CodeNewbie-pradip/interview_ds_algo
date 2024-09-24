/*
Leetcode Link           : https://leetcode.com/problems/find-the-length-of-the-longest-common-prefix/
Leetcode difficulty     : Medium
Leetcode Related Topic  : Array, Hash Table, String, Trie
Medium Article Link	    : 
*/

//------------------------------Solution - in - C++ -----------------------------------------------------------

//Approach 1: 
//T.C       : O()
//S.C       : O()
//-----------------------------------------------------------------------------------------------------------------
class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int>st;
        for(auto num:arr1){
            while(!st.count(num) && num>0){
                st.insert(num);
                num/=10;
            }
        }
        int result=0;
        for(auto num:arr2){
            while(!st.count(num) && num>0){
                num/=10;
            }
            
            if(num>0){
                result=max(result, static_cast<int>(log10(num))+1);
            }
        }
        return result;
    }
};
//-----------------------------------------------------------------------------------------------------------------
/*
Leetcode Link               : https://leetcode.com/problems/sum-of-digits-of-string-after-convert
Leetcode difficulty         : Easy
Leetcode Related Topic      : String
*/

//------------------------------Solution - in - C++ -----------------------------------------------------------

//Approach 1: Brute Approach
//T.C       : O(K.N) — k-means transformation time
//S.C       : O(n) — 

//-------------------------------------------------------------------------------------------------------------

class Solution {
public:
    int getLucky(string s, int k) {
        string num;
        for(auto c:s){
            num+=to_string(c-'a'+1);
        }
        
        while(k--){
            int totalSum=0;
            for(auto c:num){
                totalSum+=c-'0';
            }
            num=to_string(totalSum);
        }
        return stoi(num);
    }
};

//---------------------------------------------------------------------------------------------------
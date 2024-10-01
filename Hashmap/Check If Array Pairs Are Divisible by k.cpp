/*
Leetcode Link           : https://leetcode.com/problems/check-if-array-pairs-are-divisible-by-k/
Leetcode difficulty     : Medium
Leetcode Related Topic  : Array, Hash Table, Counting
Medium Article Link	    : 
*/

//------------------------------Solution - in - C++ -----------------------------------------------------------

//Approach 1: Modulus Observation
//T.C       : O(n)
//S.C       : O(k)
//-----------------------------------------------------------------------------------------------------------------
class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
     unordered_map<int, int>mp;
        
        for(auto num:arr){
            int rem=(num%k+k)%k;//handel negative case
            mp[rem]++;
        }
        
        if(mp[0]%2 != 0){
            return false;
        }
        
        for(int rem=1; rem<=k/2; rem++){
            int remainingNum=k-rem;
            if(mp[remainingNum]!=mp[rem]){
                return false;
            }
        }
        return true;
    }
};
//-----------------------------------------------------------------------------------------------------------------

/*
Leetcode Link           : https://leetcode.com/problems/rank-transform-of-an-array/
Leetcode difficulty     : Easy
Leetcode Related Topic  : Array, Hashmap, Sorting
Medium Article Link	    : 
*/

//------------------------------Solution - in - C++ -----------------------------------------------------------

//Approach 1: using hashmap
//T.C       : O(nlogn)
//S.C       : O(n)
//-----------------------------------------------------------------------------------------------------------------
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        unordered_map<int, int>mp;
        set<int> rank(arr.begin(), arr.end());
        
        int ind=1;
        for(auto r:rank){
            mp[r]=ind++;
        }
        
        vector<int>result;
        for(auto num:arr){
            result.push_back(mp[num]);
        }
        return result;
    }
};
//------------------------------------------------------------------------------------------------------------------

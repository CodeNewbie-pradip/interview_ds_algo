/*
Leetcode Link               : https://leetcode.com/problems/final-array-state-after-k-multiplication-operations-i/
Leetcode difficulty         : Easy
Leetcode Related Topic      : Array, Math 
*/

//------------------------------Solution - in - C++ -----------------------------------------------------------

//Approach 1: Brute
//T.C       : O(n) 
//S.C       : O(1) 
//-------------------------------------------------------------------------------------------------------------
class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int len=nums.size();

        for(int i=0; i<k; i++){
            int minIndex=0;
            for(int j=0; j<len; j++){
                if(nums[j]<nums[minIndex]){
                    minIndex=j;
                }
            }
            nums[minIndex]*=multiplier;

        }
        return nums;
    }
};

//--------------------------------------------------------------------------------------------------------------
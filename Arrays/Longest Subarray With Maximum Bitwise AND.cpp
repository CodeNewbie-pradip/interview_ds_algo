/*
Leetcode Link               : https://leetcode.com/problems/longest-subarray-with-maximum-bitwise-and/
Leetcode difficulty         : Medium
Leetcode Related Topic      : Array Bit Manipulation
Medium Article Link	        : 
*/

//------------------------------Solution - in - C++ -----------------------------------------------------------

//Approach 1: Brute force
//T.C       : O(n)
//S.C       : O(1)
//-----------------------------------------------------------------------------------------------------------------
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxEle=*max_element(nums.begin(), nums.end());
        
        int currlength=0, maxlength=0;
        
        for(auto num:nums){
            if(maxEle==num){
                currlength++;
                maxlength=max(maxlength, currlength);
            }else{
                currlength=0;
            }
        }
        return maxlength;
    }
};
//-----------------------------------------------------------------------------------------------------------------
//------------------------------Solution - in - Java -----------------------------------------------------------

//Approach 1   : Brute force
//T.C          : O(n)
//S.C          : O(1)
//------------------------------------------------------------------------------------------------------------------
class Solution {
    public int longestSubarray(int[] nums) {
        int maxEle = Arrays.stream(nums).max().getAsInt();
        
        int currlength = 0, maxlength = 0;
        
        for (int num : nums) {
            if (maxEle == num) {
                currlength++;
                maxlength = Math.max(maxlength, currlength);
            } else {
                currlength = 0;
            }
        }
        return maxlength;
    }
}
//--------------------------------------------------------------------------------------------------------------
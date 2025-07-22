Approach			   - Sliding Window + HashSet	
Time Complexity  - O(n)	
Space Complexity - O(n)	
Suitable For     - Best Overall
--------------------------------------------------------------------------------
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n=nums.size();

        unordered_set<int>seen;
        int left=0, right=0, currSum=0, maxSum=0;
        
        while(right<n){
            while(seen.count(nums[right])){
                currSum-=nums[left];
                seen.erase(nums[left]);
                ++left;
            }
            currSum+=nums[right];
            seen.insert(nums[right]);
            maxSum=max(currSum, maxSum);
            ++right;
        }
        
        return maxSum;
    }
};

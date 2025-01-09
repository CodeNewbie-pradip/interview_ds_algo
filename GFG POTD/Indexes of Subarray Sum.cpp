/*
GFG Link               : https://www.geeksforgeeks.org/problems/subarray-with-given-sum-1587115621/1
GFG difficulty         : Medium
GFG Related Topic      : Algorithms, Arrays, Data Structures, prefix-sum, Searching, sliding-window
*/

//------------------------------Solution - in - C++ -----------------------------------------------------------

//Approach 1: Brute Force
//T.C       : O(n^2)
//S.C       : O(1)
//-----------------------------------------------------------------------------------------------------------------
class Solution {
  public:
    vector<int> subarraySum(vector<int> &arr, int target) {
        // code here
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += arr[j];
                if (sum == target) {
                    return {i + 1, j + 1};
                }
            }
        }
        return {-1};
    }
};
//-----------------------------------------------------------------------------------------------------------------
//Approach 2: Sliding Window
//T.C       : O(n)
//S.C       : O(1)
//-----------------------------------------------------------------------------------------------------------------
class Solution {
  public:
    vector<int> subarraySum(vector<int> &arr, int target) {
        // code here
        int n=arr.size();
        int start=0;
        int sum=0;
        
        for(int end=0; end<n; end++){
            sum+=arr[end];
            
            while(sum>target && start<end){
                sum-=arr[start];
                start++;
            }
            if(sum==target){
                return {start+1, end+1};
            }
        }
        return {-1};
    }
};
//-----------------------------------------------------------------------------------------------------------------
//Approach 3 : Prefix Sum
//T.C        : O(n)
//S.C        : O(n)
//------------------------------------------------------------------------------------------------------------------
class Solution {
  public:
    vector<int> subarraySum(vector<int> &arr, int target) {
        // code here
        unordered_map<int, int> prefixMap; // To store prefix sums
        int prefixSum = 0;

        for (int i = 0; i < arr.size(); i++) {
            prefixSum += arr[i];

            if (prefixSum == target) {
                return {1, i + 1};
            }

            if (prefixMap.find(prefixSum - target) != prefixMap.end()) {
                return {prefixMap[prefixSum - target] + 2, i + 1};
            }

            prefixMap[prefixSum] = i;
        }

        return {-1};
};
//------------------------------------------------------------------------------------------------------------------

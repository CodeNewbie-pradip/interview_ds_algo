/*
GFG Link               : https://www.geeksforgeeks.org/problems/maximum-sum-of-smallest-and-second-smallest-in-an-array/1
GFG Problem difficulty : Easy
GFG Related Topic      : Sliding Window, Arrays
Medium Article Link    : 
*/

//------------------------------Solution - in - C++ -----------------------------------------------------------
//Approach 1 : Greedy Pairwise Approach (Efficient)
//T.C        : O(n)
//S.C        : O(1)
//--------------------------------------------------------------------------------------------------------------
class Solution {
  public:
    int pairWithMaxSum(vector<int>& arr) {
        // code here
        int n=arr.size();
        if(n<2){
            return -1;
        }
        int maxSum=INT_MIN;
        
        for(int i=0; i<n-1; i++){
            int first=arr[i];
            int second=arr[i+1];
            
            int sum=first+second;
            
            maxSum=max(maxSum, sum);
            
        }
        return maxSum;
    }
};
//--------------------------------------------------------------------------------------------------------------
/*
GFG Link               : https://www.geeksforgeeks.org/problems/equilibrium-point-1587115620/1
GFG Problem difficulty : Easy
GFG Related Topic      : Prefix-Sum, Arrays
*/

//------------------------------Solution - in - C++ ----------------------------------------------------------------
//Approach 1 : Brute Force
//T.C        : O(n^2)
//S.C        : O(1)
//------------------------------------------------------------------------------------------------------------------
class Solution {
  public:
    // Function to find equilibrium point in the array.
    int findEquilibrium(vector<int> &arr) {
        // code here
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            int leftSum = 0, rightSum = 0;

            // Calculate left sum
            for (int j = 0; j < i; j++) {
                leftSum += arr[j];
            }

            // Calculate right sum
            for (int j = i + 1; j < n; j++) {
                rightSum += arr[j];
            }

            // Check if left and right sums are equal
            if (leftSum == rightSum) {
                return i;
            }
        }
        return -1;
    }
};
//------------------------------------------------------------------------------------------------------------------
//Approach 2 : PreFix and Suffix sum
//T.C        : O(n)
//S.C        : O(1)
//------------------------------------------------------------------------------------------------------------------
class Solution {
  public:
    // Function to find equilibrium point in the array.
    int findEquilibrium(vector<int> &arr) {
        // code here
        int n=arr.size();
        vector<int>prefix(n, 0), suffix(n, 0);
        
        prefix[0]=arr[0];
        for(int i=1; i<n; i++){
            prefix[i]=prefix[i-1]+arr[i];
        }
            
        suffix[n-1]=arr[n-1];
        for(int i=n-2; i>=0; i--){
            suffix[i]=suffix[i+1]+arr[i];
        }
            
        for(int i=1; i<n-1; i++){
            if(prefix[i-1]==suffix[i+1]){
                return i;
            }
        }

        return -1;
    }
};
//------------------------------------------------------------------------------------------------------------------
//Approach 3 : Optimized Single Pass
//T.C        : O(n)
//S.C        : O(n)
//------------------------------------------------------------------------------------------------------------------
class Solution {
  public:
    // Function to find equilibrium point in the array.
    int findEquilibrium(vector<int> &arr) {
        // code here
        int n = arr.size();
        int totalSum = 0, leftSum = 0;

        // Calculate total sum
        for (int num : arr) {
            totalSum += num;
        }

        // Traverse array and check equilibrium
        for (int i = 0; i < n; i++) {
            int rightSum = totalSum - leftSum - arr[i];
            if (leftSum == rightSum) {
                return i;
            }
            leftSum += arr[i];
        }

        return -1;
    }
};
//------------------------------------------------------------------------------------------------------------------
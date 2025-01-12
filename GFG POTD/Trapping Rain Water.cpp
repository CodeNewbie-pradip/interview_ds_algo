/*
GFG Link      	       : https://www.geeksforgeeks.org/problems/trapping-rain-water-1587115621/1
GFG Problem difficulty : Hard
GFG Related Topic      : Array, DP, Stack, Two-Pointer
*/

//------------------------------Solution - in - C++ -----------------------------------------------------------

//Approach 1 : Brute Force
//T.C        :  O(n^2)
//S.C        :  O(1)
//------------------------------------------------------------------------------------------------------------------
class Solution {
  public:
    int maxWater(vector<int> &arr) {
        // code here
        int n = arr.size();
        int totalWater = 0;

        for (int i = 0; i < n; i++) {
            int leftMax = 0, rightMax = 0;

            for (int j = 0; j <= i; j++) {
                leftMax = max(leftMax, arr[j]);
            }
            for (int j = i; j < n; j++) {
                rightMax = max(rightMax, arr[j]);
            }

            totalWater += max(0, min(leftMax, rightMax) - arr[i]);
        }

        return totalWater;

    }
};
//------------------------------------------------------------------------------------------------------------------
//Approach 2 : PreCompute Left & Right
//T.C        : O(n)
//S.C        : O(n)
//------------------------------------------------------------------------------------------------------------------
class Solution {
  public:
    int maxWater(vector<int> &arr) {
        // code here
        int n=arr.size();
        int totalWaterCount=0;
        
        vector<int>leftMax(n, 0), rightMax(n,0);
        
        leftMax[0]=arr[0];
        for(int j=1; j<n; j++){
            leftMax[j]=max(leftMax[j-1], arr[j]);
        }
        
        rightMax[n-1]=arr[n-1];
        for(int j=n-2; j>=0; j--){
            rightMax[j]=max(rightMax[j+1], arr[j]);
        }
        
        for(int i=0; i<n; i++){
            totalWaterCount+=max(0, min(leftMax[i], rightMax[i])-arr[i]);
        }
        return totalWaterCount;
    }
};
//------------------------------------------------------------------------------------------------------------------
//Approach 3 : Two pointer
//T.C        : O(n)
//S.C        : O(1)
//------------------------------------------------------------------------------------------------------------------
class Solution {
  public:
    int maxWater(vector<int> &arr) {
        // code here
        int n = arr.size();
        if (n <= 1) return 0;
    
        int left = 0, right = n - 1;
        int leftMax = 0, rightMax = 0;
        int totalWater = 0;
    
        while (left <= right) {
            if (arr[left] <= arr[right]) {
                if (arr[left] >= leftMax) {
                    leftMax = arr[left];
                } else {
                    totalWater += leftMax - arr[left];
                }
                left++;
            } else {
                if (arr[right] >= rightMax) {
                    rightMax = arr[right];
                } else {
                    totalWater += rightMax - arr[right];
                }
                right--;
            }
        }
    
        return totalWater;
    }
};
//------------------------------------------------------------------------------------------------------------------

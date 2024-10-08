/*
GFG Link               : https://www.geeksforgeeks.org/problems/pair-sum--120604/1
GFG Problem difficulty : Easy
GFG Related Topic      : 
Medium Article Link    : 
*/

//------------------------------Solution - in - C++ -----------------------------------------------------------

//Approach 1 : Naive Approach
//T.C        : O(nlogn) 
//S.C        : O(n)
//------------------------------------------------------------------------------------------------------------------
class Solution {
    public:
      int pairsum(vector<int> &arr) {
          // code here
          sort(arr.begin(), arr.end());
          
          int n=arr.size();
          return arr[n-1]+arr[n-2];
      }
  };
//------------------------------------------------------------------------------------------------------------------
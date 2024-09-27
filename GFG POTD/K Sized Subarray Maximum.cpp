/*
GFG Link               : https://www.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k3101/1
GFG Problem difficulty : Medium
GFG Related Topic      : Sliding Window, Arrays, Queue, Data Structures, Algorithm
Medium Article Link    : 
*/

//------------------------------Solution - in - C++ -----------------------------------------------------------

//Approach 1 : Using max Heap(Priority Queue)
//T.C        : O(nlogk)
//S.C        : O(k);
//------------------------------------------------------------------------------------------------------------------
class Solution {
  public:
    // Function to find maximum of each subarray of size k.
    vector<int> max_of_subarrays(int k, vector<int> &arr) {
        // your code here
        int n=arr.size();
        priority_queue<pair<int, int>>pq;
        vector<int>result;
        
        for(int i=0; i<n; i++){
            pq.push({arr[i], i});
            
            while(!pq.empty() && pq.top().second<=i-k){
                pq.pop();
            }
            
            if(i>=k-1){
                result.push_back(pq.top().first);
            }
        }
        return result;
    }
};

//------------------------------------------------------------------------------------------------------------------
//------------------------------Solution - in - C++ -----------------------------------------------------------

//Approach 1 : Brute Force 
//T.C        : O(n*k)
//S.C        : O(1);
//------------------------------------------------------------------------------------------------------------------
class Solution {
  public:
    // Function to find maximum of each subarray of size k.
    vector<int> max_of_subarrays(int k, vector<int> &arr) {
        // your code here
        int n=arr.size();
        vector<int>result;
        
       for(int i=0; i<=n-k; i++){
           int maxVal=arr[i];
           for(int j=1; j<k; j++){
               maxVal=max(maxVal, arr[i+j]);
           }
           result.push_back(maxVal);
       }
       return result;
    }
};
//------------------------------------------------------------------------------------------------------------------

/*
GFG Link               : https://www.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1
GFG Problem difficulty : Medium
GFG Related Topic      : Array, Hash, Map, Prefix-sum
*/

//------------------------------Solution - in - C++ -----------------------------------------------------------
//Approach 1 : Hash-Map Method
//T.C        : O(n)
//S.C        : O(n)
//------------------------------------------------------------------------------------------------------------------
class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        int sum=0,length=0;
        map<int,int>mp;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
            if(sum==k) length=max(length,i+1);
            if(mp.find(sum)==mp.end()) mp[sum]=i;
            if(mp.find(sum-k)!=mp.end()) length=max(length,i-mp[sum-k]);
        }
        return length;
    }
};
//------------------------------------------------------------------------------------------------------------------
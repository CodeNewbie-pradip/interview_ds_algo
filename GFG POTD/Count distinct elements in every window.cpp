/*
GFG Link               : https://www.geeksforgeeks.org/problems/count-distinct-elements-in-every-window/1
GFG difficulty         : Easy
GFG Related Topic      : 
Medium Article Link	    : 
*/

//------------------------------Solution - in - C++ -----------------------------------------------------------
//Approach 1: Brute Force
//T.C       : O(n.k)
//S.C       : O(k)
//-------------------------------------------------------------------------------------------------------------
class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        // code here.
        int n=arr.size();
        vector<int> result;
        for(int i=0; i<=n-k; i++){
            set<int>distinct;
            for(int j=i; j<i+k; j++){
                distinct.insert(arr[j]);
            }
            result.push_back(distinct.size());
        }
        return result;
    }
};
//-------------------------------------------------------------------------------------------------------------
//Approach 2: Sliding Window with Hash Map
//T.C       : O(n)
//S.C       : O(k)
//-------------------------------------------------------------------------------------------------------------
class Solution{
    public:
    vector<int> distinctElementsSlidingWindow(vector<int>& arr, int k) {
        vector<int> result;
        unordered_map<int, int> freq;
        int n = arr.size();

        for (int i = 0; i < n; i++) {
            freq[arr[i]]++;

            if (i >= k - 1) {
                result.push_back(freq.size());

                int outElement = arr[i - k + 1];
                freq[outElement]--;

                if (freq[outElement] == 0) {
                    freq.erase(outElement);
                }
            }
        }

        return result;
    }
}
//-------------------------------------------------------------------------------------------------------------

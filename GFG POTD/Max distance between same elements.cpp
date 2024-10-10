/*
GFG Link               : https://www.geeksforgeeks.org/problems/max-distance-between-same-elements/1
GFG Problem difficulty : Easy
GFG Related Topic      : Arrays, Hash
Medium Article Link    : 
*/

//------------------------------Solution - in - C++ -----------------------------------------------------------

//Approach 1 : Using Unordered Map (Hash Map)
//T.C        : O(n)
//S.C        : O(n)
//--------------------------------------------------------------------------------------------------------------
class Solution {
  public:
    int maxDistance(vector<int> &arr) {
        // Code here
        unordered_map<int, int>firstOccurences;
        int maxDistance=0;
        int n=arr.size();
        
        for(int i=0; i<n; i++){
            if(firstOccurences.find(arr[i]) == firstOccurences.end()){
                firstOccurences[arr[i]]=i;
            }else{
                int distance=i-firstOccurences[arr[i]];
                maxDistance=max(distance, maxDistance);
            }
        }
        return maxDistance;
    }
};
//--------------------------------------------------------------------------------------------------------------
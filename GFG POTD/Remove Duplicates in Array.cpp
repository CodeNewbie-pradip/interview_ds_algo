/*
GFG Link               : https://www.geeksforgeeks.org/problems/remove-duplicates-in-small-prime-array/1
GFG Problem difficulty : Easy
GFG Related Topic      : Array Hash Prime Number 
Medium Article Link    : 
*/

//------------------------------Solution - in - C++ -----------------------------------------------------------
//Approach 1 : Using unorered_set to Maintain Order
//T.C        : O(n)
//S.C        : O(n)
//-------------------------------------------------------------------------------------------------------------
class Solution {
  public:
    vector<int> removeDuplicate(vector<int>& arr) {
        // code here
        unordered_set<int>seen;
        vector<int>result;
        for(auto num:arr){
            if(seen.find(num)==seen.end()){
                seen.insert(num);
                result.push_back(num);
            }
        }
        return result;
    }
};
//-------------------------------------------------------------------------------------------------------------
//------------------------------Solution - in - C++ -----------------------------------------------------------
//Approach 2 : Using unorered_set to Maintain Order and Count
//T.C        : O(n)
//S.C        : O(n)
//-------------------------------------------------------------------------------------------------------------
class Solution {
  public:
    vector<int> removeDuplicate(vector<int>& arr) {
        // code here
        unordered_map<int, bool> seen;
        vector<int> result;
    
        for (int num : arr) {
            if (!seen[num]) {
                seen[num] = true;
                result.push_back(num);
            }
        }
        return result;
    }
};
//-------------------------------------------------------------------------------------------------------------
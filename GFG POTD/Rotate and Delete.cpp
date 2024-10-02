/*
GFG Link               : https://www.geeksforgeeks.org/problems/rotate-and-delete-1587115621/1
GFG Problem difficulty : Medium
GFG Related Topic      : Arrays, Data structure
Medium Article Link    : 
*/

//------------------------------Solution - in - C++ -----------------------------------------------------------

//Approach 1 : 
//T.C        : O(n)
//S.C        : O(1)
//------------------------------------------------------------------------------------------------------------------
class Solution {
  public:
    int rotateDelete(vector<int> &arr) {
        // Your code here
        int sz = arr.size();
        int count =0 ;
        while(count < sz/2){     
            int x = arr[arr.size()-1]; 
            arr.insert(arr.begin()+0,x);
            arr.pop_back();   
            arr.erase(arr.begin() + arr.size()-count - 1);   
            count++;
        }
        return arr[0];
    }
};
//------------------------------------------------------------------------------------------------------------------

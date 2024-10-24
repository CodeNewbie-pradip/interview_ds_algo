/*
GFG Link               : https://www.geeksforgeeks.org/problems/ease-the-array0633/1
GFG Problem difficulty : Easy
GFG Related Topic      : Array
Medium Article Link    : 
*/

//------------------------------Solution - in - C++ -----------------------------------------------------------

//Approach 1 : Two pass Solution
//T.C        : O(n)
//S.C        : O(n)
//------------------------------------------------------------------------------------------------------------------
class Solution {
  public:
    vector<int> modifyAndRearrangeArray(vector<int> &arr) {
        // Complete the function
        int n=arr.size();
        vector<int>result(n);
        
        for(int i=0; i<n-1; i++){
            
            if(arr[i]!=0 && arr[i]==arr[i+1]){
                arr[i]*=2;
                arr[i+1]=0;
            }
        }
        
        int index=0;
            
        for(int i=0; i<n; i++){
            if(arr[i]!=0){
                result[index++]=arr[i];
            }
        }
            
        while(index<n){
            result[index++]=0;
        }
        return result;
    }
};
//------------------------------------------------------------------------------------------------------------------
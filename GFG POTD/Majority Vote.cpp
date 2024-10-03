GeeksforGeeks
/*
GFG Link               : https://www.geeksforgeeks.org/problems/majority-vote/1
GFG Problem difficulty : Medium
GFG Related Topic      : Array, Data Structure
Medium Article Link    : 
*/

//------------------------------Solution - in - C++ -----------------------------------------------------------

//Approach 1 : Booyer Moore Algorithm
//T.C        : O(n)
//S.C        : O(1)
//------------------------------------------------------------------------------------------------------------------
class Solution {
  public:
    // Function to find the majority elements in the array
    vector<int> findMajority(vector<int>& nums) {
        // Your code goes here.
        int n=nums.size();
        int candidiate1=-1, candidiate2=-1, count1=0, count2=0;
        
        for(auto num:nums){
            if(num==candidiate1){
                count1++;
            }else if(num==candidiate2){
                count2++;
            }else if(count1==0){
                candidiate1=num;
                count1=1;
            }else if(count2==0){
                candidiate2=num;
                count2=1;
            }else{
                count1--;
                count2--;
            }
        }
            
        count1=0, count2=0;
        for(auto num:nums){
            if(num==candidiate1){
                count1++;
            }else if(num==candidiate2){
                count2++;
            }
        }
        
        
        vector<int>result;
        
        if(count1>n/3){
            result.push_back(candidiate1);
        }
        if(count2>n/3){
            result.push_back(candidiate2);
        }

        if(result.empty()){
            return {-1};
        }
        
        return result;
    }
};
//------------------------------------------------------------------------------------------------------------------

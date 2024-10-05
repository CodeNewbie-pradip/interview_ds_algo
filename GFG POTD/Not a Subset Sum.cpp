/*
GFG Link               : https://www.geeksforgeeks.org/problems/smallest-number-subset1220/1
GFG Problem difficulty : Medium
GFG Related Topic      : Arrays, Data Structure
Pattern Recognition    :  For an array to represent every number up to a certain sum, the sum of all smaller numbers must cover the numbers leading up to that point. 
                          This allows you to think about gaps in the possible sums that can be generated.
                          If you have covered all numbers from 1 to sum so far with a subset, and the next element is greater than sum + 1, then sum + 1 is the smallest number that cannot be formed. 
                          This is because the gap between the subset sum and the next element is too large to "fill in" that missing number.
*/

//------------------------------Solution - in - C++ -----------------------------------------------------------

//Approach 1 : Greedy Approach (Optimal Approach)
//T.C        : O(n)
//S.C        : O(1)
//------------------------------------------------------------------------------------------------------------------
class Solution {
  public:
    long long findSmallest(vector<int> &arr) {
        // Your code goes here.
        long long res=1;
        
        for(auto num:arr){
            if(num>res){
                break;
            }
            
            res+=num;
        }
        return res;
    }
};
//------------------------------------------------------------------------------------------------------------------

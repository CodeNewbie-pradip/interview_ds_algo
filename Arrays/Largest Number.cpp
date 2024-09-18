/*
Leetcode Link               : https://leetcode.com/problems/largest-number/
Leetcode difficulty         : Medium
Leetcode Related Topic      : Array, String, Sorting, Greedy
*/

//------------------------------Solution - in - C++ -----------------------------------------------------------

//Approach 1: Brute force
//T.C       : O(n) 
//S.C       : O(1) 
//-------------------------------------------------------------------------------------------------------------
class Solution {
public:
    
    bool compare(string& a, string& b){
        return a+b > b+a;
    }
    string largestNumber(vector<int>& nums) {
        vector<string>arr;
        for(auto num:nums){
            arr.push_back(to_string(num));
        }
        sort(arr.begin(), arr.end(), compare);
                          
        if(str[i]=='0'){
            return "0";
        }
                          
        string result="";
        for(auto str:arr){
            result+=str;
        }
        return str;
    }
};
//-------------------------------------------------------------------------------------------------------------

/*
Leetcode Link               : https://leetcode.com/problems/find-missing-observations/
Leetcode difficulty         : Medium
Leetcode Related Topic      : Arrays    Math    Simulation
*/

//------------------------------Solution - in - C++ -----------------------------------------------------------

//Approach 1: Greedy Distribution
//T.C       : O(m+n)
//S.C       : O(n)
//-------------------------------------------------------------------------------------------------------------

class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m=rolls.size(); //size of the rolls
        int totalSum=mean*(n+m); //total sum of the rolls can be calculated
        int sumOfRolls=accumulate(rolls.begin(), rolls.end(), 0);
        int missingSum=totalSum-sumOfRolls;
        
        //check if sum is valid or not
        if(missingSum<n ||missingSum>n*6){
            return {};
        }
        vector<int>result(n, 1);
        missingSum-=n;
        for(int i=0; i<n && missingSum>0; i++){
            int add=min(5, missingSum);
            result[i]+=add;
            missingSum-=add;
        }
        return result;
    }
};

//---------------------------------------------------------------------------------------------------------------
//Approach 2: More Controlled Distribution
//T.C       : O(m+n)
//S.C       : O(n)
//-------------------------------------------------------------------------------------------------------------

class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m=rolls.size(); //size of the rolls
        int totalSum=mean*(n+m); //total sum of the rolls can be calculated
        int sumOfRolls=accumulate(rolls.begin(), rolls.end(), 0);
        int missingSum=totalSum-sumOfRolls;
        
        //check if sum is valid or not
        if(missingSum<n ||missingSum>n*6){
            return {};
        }
        vector<int>result(n, missingSum/n);
        int remainder=missingSum%n;
        for(int i=0; i<n && remainder>0; i++){
            result[i]++;
            remainder--;
        }
        return result;
    }
};
//---------------------------------------------------------------------------------------------------------------
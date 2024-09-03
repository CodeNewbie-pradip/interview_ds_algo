/*
Leetcode Link               : https://leetcode.com/problems/sum-of-digits-of-string-after-convert
Leetcode difficulty         : Easy
Leetcode Related Topic      : String, Simulation
*/

//------------------------------Solution - in - C++ -----------------------------------------------------------

//Approach 1: Direct String Conversion and Summation
//T.C       : O(K.N) — k-means transformation time
//S.C       : O(n) — 

//-------------------------------------------------------------------------------------------------------------

class Solution {
public:
    int getLucky(string s, int k) {
        string num;
        for(auto c:s){
            num+=to_string(c-'a'+1);
        }
        
        while(k--){
            int totalSum=0;
            for(auto c:num){
                totalSum+=c-'0';
            }
            num=to_string(totalSum);
        }
        return stoi(num);
    }
};

//---------------------------------------------------------------------------------------------------
//Approach 2: Optimized Digit Summation
//T.C       : O(K.N) — k-means transformation time
//S.C       : O(n) — 
//---------------------------------------------------------------------------------------------------
class Solution {
public:
    int getLucky(string s, int k) {
        int sum=0;
        for(auto c:s){
            int value = c-'a'+1;
            while(value>0){
                sum += value%10;
                value/=10;
            }
        }
        
        while(--k>0){
            int newSum=0;
            while(sum>0){
                newSum+=sum%10;
                sum/=10;
            }
            sum=newSum;
        }
        return sum;
    }
};
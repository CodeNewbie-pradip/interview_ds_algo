/*
Leetcode Link               : https://leetcode.com/problems/climbing-stairs/
Leetcode difficulty         : Easy
Leetcode Related Topic      : Math, Dynamic Programing, Memoisation
*/

//------------------------------Solution - in - C++ -----------------------------------------------------------

//Approach 1:Recursive Approach
//T.C       : O(2^n) — Simple but inefficient with exponential time complexity.
//S.C       : O(1)
//Error     : TLE
//-------------------------------------------------------------------------------------------------------------

class Solution {
public:
    int climbStairs(int n) {
        if(n==0 || n==1){
            return 1;
        }
        
        return climbStairs(n-2)+climbStairs(n-1);
    }
};

//-------------------------------------------------------------------------------------------------------------
//Approach 2:Memoization (Top-Down)
//T.C       : O(n)
//S.C       : O(n)
//-------------------------------------------------------------------------------------------------------------

class Solution {
public:
    int climbStairs(int n, vector<int>& dp){
        if(n==0 || n==1){
            return 1;
        }
        
        if(dp[n]!=-1){
            return dp[n];
        }
        
        dp[n]=climbStairs(n-1, dp)+climbStairs(n-2, dp);
        
        return dp[n];
    }

    int climbStairs(int n) {
        if(n==0 || n==1){
            return 1;
        }
        vector<int>dp(n+1, -1);
        return climbStairs(n, dp);
    }
};

//------------------------------------------------------------------------------------------------------------
//Approach 3:Dynamic Programming (Bottom-Up)
//T.C       : O(n)
//S.C       : O(n)
//-------------------------------------------------------------------------------------------------------------
class Solution {
public:
    int climbStairs(int n, vector<int>& dp){
        dp[0]=1;
        dp[1]=1;
        
        for(int i=2; i<=n; i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        
        return dp[n];
    }

    int climbStairs(int n) {
        if(n==0 || n==1){
            return 1;
        }
        vector<int>dp(n+1, -1);
        return climbStairs(n, dp);
    }
};
//-----------------------------------------------------------------------------------------------------------
//Approach 1:Space Optimized DP Approach
//T.C       : O(1)
//S.C       : O(n)
//------------------------------------------------------------------------------------------------------------
class Solution {
public:
    int climbStairs(int n) {
        if(n==0 || n==1){
            return 1;
        }
        
        int prev2=1;
        int prev1=1;
        int current=0;
        for(int i=2; i<=n; i++){
            current=prev1+prev2;
            prev2=prev1;
            prev1=current;
        }
        
        return current;
    }
};

//-----------------------------------------------------------------------------------------------------------
//Approach 5:Mathematical Approach
//T.C       : O(log(n))
//S.C       : O(1)
//------------------------------------------------------------------------------------------------------------
class Solution {
public:
    int climbStairs(int n) {
    double sqrt5 = std::sqrt(5);
    double phi = (1 + sqrt5) / 2;
    double psi = (1 - sqrt5) / 2;
    return std::round((std::pow(phi, n + 1) - std::pow(psi, n + 1)) / sqrt5);
    }
};

//------------------------------------------------------------------------------------------------------------
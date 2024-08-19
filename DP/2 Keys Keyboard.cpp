/*
Leetcode Link               : https://leetcode.com/problems/2-keys-keyboard/
Leetcode difficulty         : Medium
Leetcode Related Topic      : Math, Dynamic Programing
*/

//------------------------------Solution - in - C++ -----------------------------------------------------------

//Approach 1:Mathematical Approacch
//T.C       : O(sqrt(n)) — This is because we only check divisibility up to sqrt(n).
//S.C       : O(1) — No extra space other than a few variables.

class Solution {
public:
    int minSteps(int n) {
        int step=0;
        for(int i=2; i<=n; i++){
            while(n%i==0){
                step+=i;
                n/=i;
            }
        }
        return step;
    }
};


//Approach 2:Dyanamic Programming
//T.C       :O(n * sqrt(n)) — This is because for each i, we check all possible j up to sqrt(i).
//S.C       :O(n) — This is for storing the dp array.
class Solution {
public:
    int minSteps(int n) {
        vector<int>dp(n+1, INT_MAX);
        dp[1]=0;
        for(int i=2; i<=n; i++){
            for(int j=1; j<i; j++){
                if(i % j == 0){
                    dp[i]=min(dp[i], dp[j]+i/j);
                }
            }
        }
        return dp[n];
    }
};

//-----------------------------------------------------------------

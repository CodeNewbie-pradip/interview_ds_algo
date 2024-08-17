/*
Leetcode Link               : https://leetcode.com/problems/maximum-number-of-points-with-cost/
Leetcode difficulty         : Medium
Leetcode Related Topic      : Array, Dynamic Programing
*/

//------------------------------Solution - in - C++ -----------------------------------------------------------

//Approach 1:Dynamic Programming with Brute force(just applying concept)
//T.C       :O(n*m^2)  &  S.C   :O(m)
//Error     :TLE
class Solution {
public:
    typedef long long ll;
    long long maxPoints(vector<vector<int>>& points) {
        //step 1: calculate lenth of row and column
        int n=points.size();
        int m=points[0].size();
        
        //step 2:create array to store previous value
        vector<ll>prev(m);
        for(int i=0; i<m; i++){
            prev[i]=points[0][i];
        }
        
        //step 3:
        for(int i = 1; i < n; i++){
            vector<ll>curr(m);
            for(int j = 0; j < m; j++){
                for(int k = 0; k < m; k++){
                    curr[j]=max(curr[j], prev[k]+points[i][j]-abs(j-k));
                }
            }
            prev=curr;
        }
        return *max_element(begin(prev), end(prev));
    }
};

//-------------------------------------------------------------------------------------

//Approach 2:Optimized Dynamic Programming with Left and Right Passes
//T.C       :O(n*m)  &  S.C   :O(m)

class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int m = points.size();
        int n = points[0].size();
        vector<long long> prevRow(points[0].begin(), points[0].end());

        for (int r = 1; r < m; ++r) {
            vector<long long> left(n, 0), right(n, 0), currRow(n, 0);

            left[0] = prevRow[0];
            for (int j = 1; j < n; ++j) {
                left[j] = max(left[j-1] - 1, prevRow[j]);
            }
    
            right[n-1] = prevRow[n-1];
            for (int j = n-2; j >= 0; --j) {
                right[j] = max(right[j+1] - 1, prevRow[j]);
            }
    
            for (int j = 0; j < n; ++j) {
                currRow[j] = points[r][j] + max(left[j], right[j]);
            }
    
            prevRow = currRow;
    }

    return *max_element(prevRow.begin(), prevRow.end());
    }
};

//-------------------------------------------------------------------------------------

//Approach 3:Space-Optimized DP with Single Pass
//T.C       :O(n*m)  &  S.C   :O(m)

class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int m = points.size();
        int n = points[0].size();
        vector<long long> dp(points[0].begin(), points[0].end());
    
        for (int r = 1; r < m; ++r) {
            vector<long long> left(n, 0), right(n, 0);
    
            left[0] = dp[0];
            for (int j = 1; j < n; ++j) {
                left[j] = max(left[j-1] - 1, dp[j]);
            }
    
            right[n-1] = dp[n-1];
            for (int j = n-2; j >= 0; --j) {
                right[j] = max(right[j+1] - 1, dp[j]);
            }
    
            for (int j = 0; j < n; ++j) {
                dp[j] = points[r][j] + max(left[j], right[j]);
            }
        }

    return *max_element(dp.begin(), dp.end());
    }
};

------------------------------------------------------------------

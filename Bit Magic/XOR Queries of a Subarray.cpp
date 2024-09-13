/*
Leetcode Link               : https://leetcode.com/problems/xor-queries-of-a-subarray/
Leetcode difficulty         : Medium
Leetcode Related Topic      : Array, Bit Manipulation, Prefix Sum
Medium Article Link	        : https://medium.com/@pradipalabade/1310-xor-queries-of-a-subarray-eaf2b4da4801
*/

//------------------------------Solution - in - C++ -----------------------------------------------------------

//Approach 1: Brute force
//T.C       : O(q*n)
//S.C       : O(1)
//-------------------------------------------------------------------------------------------------------------
class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> prefixXor(n);
        prefixXor[0] = arr[0];
        
        // Build the prefix XOR array
        for (int i = 1; i < n; ++i) {
            prefixXor[i] = prefixXor[i - 1] ^ arr[i];
        }
        
        vector<int> result;
        
        // Answer each query
        for (auto& query : queries) {
            int left = query[0], right = query[1];
            if (left == 0) {
                result.push_back(prefixXor[right]);
            } else {
                result.push_back(prefixXor[right] ^ prefixXor[left - 1]);
            }
        }
        
        return result;
    }
};
//-------------------------------------------------------------------------------------------------------------
//Approach 2: Prefix XOR Sum
//T.C       : O(n+q)
//S.C       : O(n)
//-------------------------------------------------------------------------------------------------------------
class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> prefixXor(n);
        prefixXor[0] = arr[0];
        
        // Build the prefix XOR array
        for (int i = 1; i < n; ++i) {
            prefixXor[i] = prefixXor[i - 1] ^ arr[i];
        }
        
        vector<int> result;
        
        // Answer each query
        for (auto& query : queries) {
            int left = query[0], right = query[1];
            if (left == 0) {
                result.push_back(prefixXor[right]);
            } else {
                result.push_back(prefixXor[right] ^ prefixXor[left - 1]);
            }
        }
        
        return result;
    }
};

//-------------------------------------------------------------------------------------------------------------

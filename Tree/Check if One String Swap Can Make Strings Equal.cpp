// LeetCode URL: https://leetcode.com/problems/check-if-one-string-swap-can-make-strings-equal/
// LeetCode Difficulty: Easy
// LeetCode Tags: String
//----------------------------------------------------------------------------------------------------
//Approach 1 : Direct comparision and mismatch tracking
//Time Complexity : O(n)
//Space Complexity : O(1)
//----------------------------------------------------------------------------------------------------
class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if (s1 == s2) return true; // No swap needed
        
        vector<int> diffIndices;
        
        for (int i = 0; i < s1.length(); i++) {
            if (s1[i] != s2[i]) {
                diffIndices.push_back(i);
            }
        }

        if (diffIndices.size() != 2) return false;

        // Check if swapping the two differing characters makes the strings equal
        int i = diffIndices[0], j = diffIndices[1];
        return (s1[i] == s2[j] && s1[j] == s2[i]);
    }
};
//----------------------------------------------------------------------------------------------------
//Approach 2 : Brute Force (Try All Possible Swaps)
//Time Complexity : O(n^2)
//Space Complexity : O(1)
//----------------------------------------------------------------------------------------------------
class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if (s1 == s2) return true; // Already equal

        int n = s1.size();
        
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                swap(s1[i], s1[j]);  // Perform swap
                if (s1 == s2) return true;
                swap(s1[i], s1[j]);  // Revert swap
            }
        }
        
        return false;
    }
};
//----------------------------------------------------------------------------------------------------
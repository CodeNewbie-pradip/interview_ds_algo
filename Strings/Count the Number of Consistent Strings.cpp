/*
Leetcode Link               : https://leetcode.com/problems/count-the-number-of-consistent-strings/
Leetcode difficulty         : Easy
Leetcode Related Topic      : String, Hash Table, String, Bit Manipulation, Counting
Medium Article Link	        : https://medium.com/@pradipalabade/count-the-number-of-consistent-strings-35277823e9e2
*/

//------------------------------Solution - in - C++ -----------------------------------------------------------

//Approach 1: Using a Set for Allowed Characters
//T.C       : O(n*m)
//S.C       : O(k)
//-------------------------------------------------------------------------------------------------------------
class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        // Create a set of allowed characters for O(1) lookup
        unordered_set<char> allowedSet(allowed.begin(), allowed.end());
        
        int consistentCount = 0;
        
        // Check each word
        for (const string& word : words) {
            bool isConsistent = true;
            for (char c : word) {
                if (allowedSet.find(c) == allowedSet.end()) {
                    isConsistent = false;
                    break;
                }
            }
            if (isConsistent) {
                consistentCount++;
            }
        }
        
        return consistentCount;
    }
};
//-------------------------------------------------------------------------------------------------------------
//Approach 2: Bitmasking (Optimized)
//T.C       : O(n*m)
//S.C       : O(1)
//-------------------------------------------------------------------------------------------------------------
class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        // Create a bitmask for the allowed characters
        int allowedMask = 0;
        for (char c : allowed) {
            allowedMask |= (1 << (c - 'a'));
        }
        
        int consistentCount = 0;
        
        // Check each word using bitmasks
        for (const string& word : words) {
            int wordMask = 0;
            for (char c : word) {
                wordMask |= (1 << (c - 'a'));
            }
            // If wordMask is a subset of allowedMask
            if ((wordMask & allowedMask) == wordMask) {
                consistentCount++;
            }
        }
        
        return consistentCount;
    }
};
//--------------------------------------------------------------------------------------------------------
//Approach 3    : Array Lookup
//T.C           : O(n*m)
//S.C           : O(1)
//--------------------------------------------------------------------------------------------------------
class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        // Create an array to mark allowed characters
        bool allowedArr[26] = {false};
        for (char c : allowed) {
            allowedArr[c - 'a'] = true;
        }
        
        int consistentCount = 0;
        
        // Check each word
        for (const string& word : words) {
            bool isConsistent = true;
            for (char c : word) {
                if (!allowedArr[c - 'a']) {
                    isConsistent = false;
                    break;
                }
            }
            if (isConsistent) {
                consistentCount++;
            }
        }
        
        return consistentCount;
    }
};
//-------------------------------------------------------------------------------------------------------
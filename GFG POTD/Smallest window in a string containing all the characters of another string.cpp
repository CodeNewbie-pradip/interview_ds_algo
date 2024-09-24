GeeksforGeeks
/*
GFG Link               : https://www.geeksforgeeks.org/problems/smallest-window-in-a-string-containing-all-the-characters-of-another-string-1587115621/1
GFG Problem difficulty : Hard
GFG Related Topic      : sliding-window, Hash, Strings, Dynamic Programming, Data Structures, Algorithms
Medium Article Link    : 
*/

//------------------------------Solution - in - C++ -----------------------------------------------------------

//Approach 1 : Sliding Window(Two Pointer)
//T.C        : O(n)
//S.C        : O(1)/O(26)
//------------------------------------------------------------------------------------------------------------------
class Solution {
public:
    // Function to find the smallest window in the string `s` consisting
    // of all the characters of string `p`.
    string smallestWindow(string s, string p) {
        // Frequency map for characters in string `p`.
        vector<int> freq(26, 0);
        for (char c : p) {
            freq[c - 'a']++;
        }
        
        // Temporary frequency map to track characters in the current window of `s`.
        vector<int> tempCnt(26, 0);
        int n = s.length();
        int i = 0, j = 0;      // Pointers to the sliding window.
        int minLen = INT_MAX;   // To store the length of the smallest window.
        int start = -1;         // To store the starting index of the smallest window.
        
        // Helper function to check if the current window contains all characters of `p`.
        auto containsAllChars = [&]() -> bool {
            for (int k = 0; k < 26; k++) {
                if (freq[k] > tempCnt[k]) {
                    return false;
                }
            }
            return true;
        };
        
        // Expanding the window by moving the `j` pointer.
        while (j < n) {
            tempCnt[s[j] - 'a']++;  // Add character `s[j]` to the current window.
            
            // Check if the current window contains all characters of `p`.
            if (!containsAllChars()) {
                j++;
            } else {
                // Try to minimize the window by moving the `i` pointer.
                while (containsAllChars()) {
                    if (j - i + 1 < minLen) {
                        minLen = j - i + 1;
                        start = i;  // Update the starting index of the smallest window.
                    }
                    tempCnt[s[i] - 'a']--;  // Remove `s[i]` from the window.
                    i++;  // Shrink the window from the left.
                }
                j++;
            }
        }
        
        // If no valid window is found, return "-1". Otherwise, return the smallest window.
        return minLen == INT_MAX ? "-1" : s.substr(start, minLen);
    }
};

//------------------------------------------------------------------------------------------------------------------

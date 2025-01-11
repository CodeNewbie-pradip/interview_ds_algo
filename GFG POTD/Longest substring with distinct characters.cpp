/*
GFG Link               : 
GFG difficulty         : Easy
GFG Related Topic      : 
*/

//------------------------------Solution - in - C++ -----------------------------------------------------------
//Approach 1: Brute Force
//T.C       : O(n^2)
//S.C       : O(k)
//-------------------------------------------------------------------------------------------------------------
class Solution{
    public:
    int longestSubstringBruteForce(const string& s) {
        int n = s.size();
        int maxLength = 0;

        for (int i = 0; i < n; i++) {
            set<char> seen;
            for (int j = i; j < n; j++) {
                if (seen.find(s[j]) != seen.end()) break;
                seen.insert(s[j]);
                maxLength = max(maxLength, j - i + 1);
            }
        }

        return maxLength;
    }
};
//-------------------------------------------------------------------------------------------------------------
//Approach 2: Sliding Window
//T.C       : O(n)
//S.C       : O(k)
//-------------------------------------------------------------------------------------------------------------
class solution{
    public:
    int longestSubstringSlidingWindow(const string& s) {
        int n = s.size();
        int left = 0, maxLength = 0;
        unordered_set<char> seen;

        for (int right = 0; right < n; right++) {
            while (seen.find(s[right]) != seen.end()) {
                seen.erase(s[left]);
                left++;
            }
            seen.insert(s[right]);
            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};
//-------------------------------------------------------------------------------------------------------------
//Approach 3: Optimized Sliding Window with Hash Map
//T.C       : O(n)
//S.C       : O(k)
//-------------------------------------------------------------------------------------------------------------
class solution{
    public:
    int longestSubstringOptimized(const string& s) {
        int n = s.size();
        unordered_map<char, int> lastIndex;
        int maxLength = 0, left = 0;

        for (int right = 0; right < n; right++) {
            if (lastIndex.find(s[right]) != lastIndex.end()) {
                left = max(left, lastIndex[s[right]] + 1);
            }
            lastIndex[s[right]] = right;
            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};
//-------------------------------------------------------------------------------------------------------------
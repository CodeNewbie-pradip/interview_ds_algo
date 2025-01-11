/*
Leetcode Link               : https://leetcode.com/problems/construct-k-palindrome-strings/?envType=daily-question&envId=2025-01-11
Leetcode difficulty         : Medium
Leetcode Related Topic      : Hash Table, String Greedy Counting
*/

//------------------------------Solution - in - C++ -----------------------------------------------------------
//Approach 1: Count Odd Frequencies
//T.C       : O(n)
//S.C       : O(1)
//-----------------------------------------------------------------------------------------------------------------
class Solution {
public:
    bool canConstruct(string s, int k) {
        int n=s.length();
        unordered_map<char, int>mp;
        if(n<k) return false;

        for(auto ch:s) mp[ch]++;

        int oddCount=0;
        
        for(auto [ch, freq]:mp){
            if(freq%2==1){
                oddCount++;
            }
        }
        
        return k>=oddCount;
    }
};
//-----------------------------------------------------------------------------------------------------------------
//Approach 2: Bitmasking
//T.C       : O(n)
//S.C       : O(1)
//-----------------------------------------------------------------------------------------------------------------
class Solution {
public:
    bool canConstruct(string s, int k) {
        if (k > s.length()) return false; // More palindromes than characters
        int bitmask = 0;
        for (char c : s) {
            bitmask ^= (1 << (c - 'a')); // Toggle bit for character
        }
        
        int oddCount = __builtin_popcount(bitmask); // Count 1s in bitmask
        return oddCount <= k;
    }
};
//-----------------------------------------------------------------------------------------------------------------
//Approach 3: Frequency Array
//T.C       : O(n)
//S.C       : O(1)
//-----------------------------------------------------------------------------------------------------------------
class Solution {
public:
    bool canConstruct(string s, int k) {
        if (k > s.length()) return false; // More palindromes than characters
        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }
        
        int oddCount = 0;
        for (int count : freq) {
            if (count % 2 != 0) oddCount++;
        }
        
        return oddCount <= k;
    }
};
//-----------------------------------------------------------------------------------------------------------------
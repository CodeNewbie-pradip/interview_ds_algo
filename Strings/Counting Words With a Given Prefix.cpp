/*
Leetcode Link          : https://leetcode.com/problems/counting-words-with-a-given-prefix/description/?envType=daily-question&envId=2025-01-09
Leetcode difficulty    : Easy
Leetcode Related Topic : Arrays, String, String Matching
*/

//------------------------------Solution - in - C++ -----------------------------------------------------------

//Approach 1: Brute Force Using substring
//T.C       : O(n.m)
//S.C       : O(1)
//--------------------------------------------------------------------------------------------------------------
class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int count=0;
        for(auto word:words){
            if(word.substr(0, pref.length())==pref){
                count++;
            }
        }
        return count;
    }
};
//--------------------------------------------------------------------------------------------------------------
//Approach 2: Direct String Comparision
//T.C       : O(n.m)
//S.C       : O(1)
//--------------------------------------------------------------------------------------------------------------
class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int count = 0;
        int prefLen = pref.size();

        for (const string& word : words) {
            if (word.size() >= prefLen && equal(pref.begin(), pref.end(), word.begin())) {
                count++;
            }
        }
        
        return count;
    }
};

//--------------------------------------------------------------------------------------------------------------
//Approach 3 : Using STL
//T.C        : O(n.m)
//S.C        : O(1)
//--------------------------------------------------------------------------------------------------------------
class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int count = 0;

        for (const string& word : words) {
            if (word.size() >= pref.size()) {
                auto mismatchPair = mismatch(pref.begin(), pref.end(), word.begin());
                if (mismatchPair.first == pref.end()) {
                    count++;
                }
            }
        }
        
        return count;
    }
};
//--------------------------------------------------------------------------------------------------------------

/*
Leetcode Link      	        : https://leetcode.com/problems/count-prefix-and-suffix-pairs-i/description/?envType=daily-question&envId=2025-01-08
Leetcode Problem difficulty : Easy
Leetcode Related Topic      : Array, String, Trie, Rolling Hash, String Matching, Hash Function
*/

//------------------------------Solution - in - C++ -----------------------------------------------------------

//Approach 1 : Brute force
//T.C        : O(n^2*m)
//S.C        : O(1)
//-------------------------------------------------------------------------------------------------------------
class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();
        int count = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (isPrefixAndSuffix(words[i], words[j])) {
                    count++;
                }
            }
        }

        return count;
    }

private:
    bool isPrefixAndSuffix(const string& str1, const string& str2) {
        int len1 = str1.size(), len2 = str2.size();
        if (len1 > len2) return false; // str1 cannot be both prefix and suffix if it's longer

        return str2.substr(0, len1) == str1 && str2.substr(len2 - len1) == str1;
    }
};

//-------------------------------------------------------------------------------------------------------------
//Approach 2 : Optimize with String Comparison
//T.C        : O(n^2*m)
//S.C        : O(1)
//------------------------------------------------------------------------------------------------------------
class Solution {
public:
    bool isPrefixAndSuffix(const string& str1, const string& str2) {
        int len1 = str1.size(), len2 = str2.size();
        if (len1 > len2) return false; // str1 cannot be both prefix and suffix if it's longer

        return str2.substr(0, len1) == str1 && str2.substr(len2 - len1) == str1;
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int n=words.size();
        int count=0;
        
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(isPrefixAndSuffix(words[i], words[j])){
                    count++;
                }
            }
        }
        return count;
    }
};
//------------------------------------------------------------------------------------------------------------
//Approach 3 : 
//T.C        : 
//S.C        :
//------------------------------------------------------------------------------------------------------------

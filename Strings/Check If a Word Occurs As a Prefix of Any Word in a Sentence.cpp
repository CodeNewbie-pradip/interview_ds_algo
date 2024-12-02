/*
Leetcode Link           : https://leetcode.com/problems/check-if-a-word-occurs-as-a-prefix-of-any-word-in-a-sentence/
Leetcode difficulty     : Easy
Leetcode Related Topic  : Two Pointers, String, String Matching
Medium Article Link	    : 
*/

//------------------------------Solution - in - C++ -----------------------------------------------------------

//Approach 1: Split Sentence and Check Prefix
//T.C       : O(n+k) -> n-length of sentence, k-total length of all words
//S.C       : O(w) ->number of words
//-------------------------------------------------------------------------------------------------------------
class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        stringstream ss(sentence);
        string word;
        int index=1;
        
        while(ss>>word){
            if(word.find(searchWord)==0){
                return index;
            }
            index++;
        }
        return -1;
    }
};
//-------------------------------------------------------------------------------------------------------------
//Approach 2: Manual Parsing
//T.C       : O(n)
//S.C       : O(1)
//-------------------------------------------------------------------------------------------------------------
class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int index=1, i=0, n=sentence.size();
        
        while(i<n){
            int start=i;
            while(i<n && sentence[i]!=' '){
                i++;
            }
            
            string word=sentence.substr(start, i-start);
            if(word.find(searchWord)==0){
                return index;
            }
            
            index++;
            i++;
        }
        return -1;
    }
};
//-------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------
//Approach 3: 
//T.C       : O(n*m)->n-length of the sentece, and m is the length of the sentence
//S.C       : O(1)->no extra space used
//-------------------------------------------------------------------------------------------------------------
class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int n = sentence.size(), m = searchWord.size();
        int index = 1, i = 0;

        while (i < n) {
            int j = 0;
            if (sentence[i] != ' ') {
                int start = i;
                while (j < m && start < n && sentence[start] == searchWord[j]) {
                    start++;
                    j++;
                }

                if (j == m) { // If all characters of searchWord match
                    return index;
                }

                // Move to the end of the current word
                while (i < n && sentence[i] != ' ') {
                    i++;
                }
            }

            index++;
            i++;
        }

        return -1;
    }
};
//-------------------------------------------------------------------------------------------------------------
//Approach 4: Using STL
//T.C       : O(n+k)
//S.C       : O(w)
//-------------------------------------------------------------------------------------------------------------
class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int n = sentence.size(), m = searchWord.size();
        int index = 1, i = 0;

        while (i < n) {
            int start = i;
            while (i < n && sentence[i] != ' ') {
                i++;
            }

            string word = sentence.substr(start, i - start);
            if (word.compare(0, m, searchWord) == 0) {
                return index;
            }

            index++;
            i++;
        }

        return -1;
    }
};
//-------------------------------------------------------------------------------------------------------------

/*
Leetcode Link               : https://leetcode.com/problems/reverse-words-in-a-string/
Leetcode difficulty         : Medium
Leetcode Related Topic      : Two Pointer, String
Medium Article Link	        : 
*/

//------------------------------Solution - in - C++ --------------------------------------------------------------

//Approach 1: Split, Reverse, and Join
//T.C       : O(n)
//S.C       : O(n)
//-----------------------------------------------------------------------------------------------------------------
class Solution {
public:
    string reverseWords(string s) {
        vector<string>words;
        stringstream ss(s);
        string word;
        
        while(ss>>word){
            words.push_back(word);
        }
        
        reverse(words.begin(), words.end());
        
        string result="";
        for(int i=0; i<words.size(); i++){
            if(i>0){
                result+=" ";
            }
            result+=words[i];
        }
        
        return result;
    }
};
//-----------------------------------------------------------------------------------------------------------------
//Approach 2: 
//T.C       : O()
//S.C       : O()
//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------

//------------------------------Solution - in - Java --------------------------------------------------------------

//Approach 1 : 
//T.C        :
//S.C        :
//------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------

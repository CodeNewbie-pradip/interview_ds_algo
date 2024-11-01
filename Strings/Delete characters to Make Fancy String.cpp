/*
Leetcode Link          : https://leetcode.com/problems/delete-characters-to-make-fancy-string/
Leetcode difficulty    : Easy
Leetcode Related Topic : String
Medium Article Link	   : 
*/

//------------------------------Solution - in - C++ -----------------------------------------------------------
//Approach 1: Greedy with Stack-like Construction
//T.C       : O(n)
//S.C       : O(n)
//-----------------------------------------------------------------------------------------------------------------
class Solution {
public:
    string makeFancyString(string s) {
        string result="";
        
        for(auto c:s){
            int len=result.size();
            if(len>=2 && result[len-1]==c && result[len-2]==c){
                continue;
            }
            result+=c;
        }
        return result;
    }
};
//-----------------------------------------------------------------------------------------------------------------
//Approach 2: In Place Modification
//T.C       : O(n)
//S.C       : O(1)
//-----------------------------------------------------------------------------------------------------------------
class Solution {
public:
    string makeFancyString(string s) {
        int j=0;
        for(int i=0; i<s.length(); i++){
            if(j>=2 && s[j-1]==s[i] && s[j-1]==s[i]){
                continue;
            }
            s[j++]+=s[i];
        }
        return s;
    }
};
//-----------------------------------------------------------------------------------------------------------------
//------------------------------Solution - in - Java -----------------------------------------------------------

//Approach 1 : 
//T.C                :
//S.C                :
//------------------------------------------------------------------------------------------------------------------

GeeksforGeeks
/*
GFG Link      	       : 
GFG Problem difficulty : 
GFG Related Topic      : 
Medium Article Link    : 
*/

//------------------------------Solution - in - C++ -----------------------------------------------------------

//Approach 1 : Using Stack
//T.C        : O(n)
//S.C        : O(n)
//------------------------------------------------------------------------------------------------------------------
class Solution {
  public:
    string reverseWords(string str) {
        // code here
        string result="";
        string word="";
        stack<string>words;
        for(auto s:str){
            if(s=='.'){
                words.push(word);
                word="";
            }else{
                word+=s;
            }
        }
        words.push(word);
        while(!words.empty()){
            result+=words.top();
            words.pop();
            if(!words.empty()){
                result+='.';
            }
        }
        return result;
    }
};
//------------------------------------------------------------------------------------------------------------------

//Approach 2 : Two Pointer Approach without Extra Space
//T.C        : O(n)
//S.C        : O(1)

//------------------------------------------------------------------------------------------------------------------
class Solution {
  public:
    void reverseWord(string &str, int start, int end) {
        while (start < end) {
            swap(str[start], str[end]);
            start++;
            end--;
        }
    }
    
    string reverseWordsInPlace(string str) {
        int n = str.size();
        
        // Reverse the entire string
        reverse(str.begin(), str.end());
    
        // Reverse each word in the reversed string
        int start = 0;
        for (int end = 0; end <= n; end++) {
            if (end == n || str[end] == '.') {
                reverseWord(str, start, end - 1);
                start = end + 1;
            }
        }
    
        return str;
    }
};

//------------------------------------------------------------------------------------------------------------------

//Approach 3 : Using Split, Reverse, and Join
//T.C        : O(n)
//S.C        : O(n)

//------------------------------------------------------------------------------------------------------------------
class Solution{
    public:
    string reverseWordsInPlace(string str)
    {
        vector<string> words;
        string word;
        stringstream ss(str);

        // Split the string by '.'
        while (getline(ss, word, '.')) {
            words.push_back(word);
        }

        // Reverse the vector of words
        reverse(words.begin(), words.end());

        // Join the reversed words with '.'
        string result;
        for (int i = 0; i < words.size(); ++i) {
            result += words[i];
            if (i < words.size() - 1) {
                result += ".";
            }
        }
    return result;
    }
};
//------------------------------------------------------------------------------------------------------------------

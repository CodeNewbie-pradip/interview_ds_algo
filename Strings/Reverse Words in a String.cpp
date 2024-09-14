/*
Leetcode Link               : https://leetcode.com/problems/reverse-words-in-a-string/
Leetcode difficulty         : Medium
Leetcode Related Topic      : Two Pointer, String
Medium Article Link	        : https://medium.com/@pradipalabade/151-reverse-words-in-a-string-1be0042a2dab
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
//Approach 2: Stack Based 
//T.C       : O(n)
//S.C       : O(n)
//-----------------------------------------------------------------------------------------------------------------
class Solution {
public:
    string reverseWords(string s) {
         stack<string> wordStack;
    stringstream ss(s);
    string word;
    
    // Step 1: Push all words to the stack
    while (ss >> word) {
        wordStack.push(word);
    }
    
    // Step 2: Pop from the stack and form the result
    string result = "";
    while (!wordStack.empty()) {
        if (!result.empty()) {
            result += " ";
        }
        result += wordStack.top();
        wordStack.pop();
    }
    
    return result;
    }
};
//-----------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------
//Approach 3: Two Pointer
//T.C       : O(n)
//S.C       : O(n)
//-----------------------------------------------------------------------------------------------------------------
class Solution {
public:
    string reverseWords(string s) {
         string result = "";
    int n = s.size();
    int i = n - 1;
    
    while (i >= 0) {
        while (i >= 0 && s[i] == ' ') i--; // Skip spaces
        if (i < 0) break;
        int j = i;
        while (i >= 0 && s[i] != ' ') i--; // Find the word
        if (!result.empty()) result += " ";
        result += s.substr(i + 1, j - i); // Add the word
    }
    
    return result;
    }
};

//------------------------------Solution - in - Java --------------------------------------------------------------

//Approach 1 : Split, Reverse, and Join
//T.C        : O(n)
//S.C        : O(n)
//------------------------------------------------------------------------------------------------------------------
class Solution {
    public String reverseWords(String s) {
        List<String> words = new ArrayList<>();
        Scanner scanner = new Scanner(s);
        
        while (scanner.hasNext()) {
            words.add(scanner.next());
        }
        
        Collections.reverse(words);
        
        StringBuilder result = new StringBuilder();
        for (int i = 0; i < words.size(); i++) {
            if (i > 0) {
                result.append(" ");
            }
            result.append(words.get(i));
        }
        
        return result.toString();
    }
}
//-----------------------------------------------------------------------------------------------------------------
//Approach 2: Stack Based 
//T.C       : O(n)
//S.C       : O(n)
//-----------------------------------------------------------------------------------------------------------------
class Solution {
    public String reverseWords(String s) {
        Stack<String> wordStack = new Stack<>();
        Scanner scanner = new Scanner(s);
        
        // Step 1: Push all words to the stack
        while (scanner.hasNext()) {
            wordStack.push(scanner.next());
        }
        
        // Step 2: Pop from the stack and form the result
        StringBuilder result = new StringBuilder();
        while (!wordStack.isEmpty()) {
            if (result.length() > 0) {
                result.append(" ");
            }
            result.append(wordStack.pop());
        }
        
        return result.toString();
    }
}
//-----------------------------------------------------------------------------------------------------------------
//Approach 3: Two Pointer
//T.C       : O(n)
//S.C       : O(n)
//-----------------------------------------------------------------------------------------------------------------
class Solution {
    public String reverseWords(String s) {
        String result = "";
        int n = s.length();
        int i = n - 1;
        
        while (i >= 0) {
            while (i >= 0 && s.charAt(i) == ' ') i--; // Skip spaces
            if (i < 0) break;
            int j = i;
            while (i >= 0 && s.charAt(i) != ' ') i--; // Find the word
            if (!result.isEmpty()) result += " ";
            result += s.substring(i + 1, j + 1); // Add the word
        }
        
        return result;
    }
}
//-----------------------------------------------------------------------------------------------------------------

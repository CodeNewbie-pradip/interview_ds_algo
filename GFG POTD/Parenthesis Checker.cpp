GeeksforGeeks
/*
GFG Link      	       : https://www.geeksforgeeks.org/problems/parenthesis-checker2744/1
GFG Problem difficulty : Easy
GFG Related Topic      :  String, stack, STL, Data Structure
*/

//------------------------------Solution - in - C++ -----------------------------------------------------------

//Approach 1 : Using Stock
//T.C        : O(n)
//S.C        : O(n)

//--------------------------------------------------------------------------------------------------------------
class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool isMatching(char open, char close){
        return ((open=='(' && close==')') || 
                (open=='{' && close=='}') ||
                (open=='[' && close==']')
                );
    }
    bool ispar(string x)
    {
        // Your code here
        stack<char>st;
        for(auto c:x){
            if(c=='(' || c=='{' || c=='['){
                st.push(c);
            }else{
                if(st.empty() || !isMatching(st.top(), c)){
                    return false;
                }
                st.pop();
            }
        }
        return st.empty()?true:false;
    }

};
//------------------------------Solution - in - Java -----------------------------------------------------------

//Approach 1 : Using Stock
//T.C        : O(n)
//S.C        : O(n)

//--------------------------------------------------------------------------------------------------------------
class Solution {
    // Function to check if brackets are balanced or not.
    public boolean isMatching(char open, char close) {
        return ((open == '(' && close == ')') || 
                (open == '{' && close == '}') ||
                (open == '[' && close == ']'));
    }

    public boolean ispar(String x) {
        Stack<Character> st = new Stack<>();
        for (char c : x.toCharArray()) {
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            } else {
                if (st.isEmpty() || !isMatching(st.peek(), c)) {
                    return false;
                }
                st.pop();
            }
        }
        return st.isEmpty();
    }
}

//--------------------------------------------------------------------------------------------------------------
/*
Leetcode Link               : https://leetcode.com/problems/different-ways-to-add-parentheses/
Leetcode difficulty         : Medium
Leetcode Related Topic      : Math, String, Dynamic Programming, Recursion, Memoization
Medium Article Link	        : 
*/

//------------------------------Solution - in - C++ -----------------------------------------------------------

//Approach 1: Recursive Divide and Conquer
//T.C       : O(2^n)
//S.C       : O(n)
//-----------------------------------------------------------------------------------------------------------------
class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
     vector<int>result;
    for(int i=0; i<expression.size(); i++){
            char c=expression[i];
        
            if(c=='+' || c=='-' || c=='*'){
                vector<int>left=diffWaysToCompute(expression.substr(0, i));
                vector<int>right=diffWaysToCompute(expression.substr(i+1));
                
                for(auto l:left){
                    for(auto r:right){
                        if(c=='+'){
                            result.push_back(l+r);
                        }else if(c=='-'){
                            result.push_back(l-r);
                        }else{
                            result.push_back(l*r);
                        }
                    }
                }
            }
        }
        if(result.empty()){
                result.push_back(stoi(expression));
            }
        return result;
    }
};
//-----------------------------------------------------------------------------------------------------------------
//Approach 2: Divide and Conquer + Memoisation
//T.C       : O(n^3)
//S.C       : O(n^2)
//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------

//Approach 3 :Dynamic Programming 
//T.C        : O(n^3)
//S.C        : O(n^2)
//------------------------------------------------------------------------------------------------------------------

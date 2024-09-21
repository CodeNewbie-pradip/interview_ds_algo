/*
Leetcode Link               : https://leetcode.com/problems/lexicographical-numbers/
Leetcode difficulty         : Medium
Leetcode Related Topic      : DFS, Trie
*/

//------------------------------Solution - in - C++ -----------------------------------------------------------

//Approach 1: 
//T.C       : O(n)
//S.C       : O(1)
//-----------------------------------------------------------------------------------------------------------------
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        
        vector<int>result;
        int curr=1;
        for(int i=0; i<n; i++)
        {
            result.push_back(curr);
            if(curr*10<=n){
                curr*=10;
            }else{
                if(curr>=n){
                    curr/=10;
                }
                curr+=1;
                while(curr%10==0){
                    curr/=10;
                }
            }
        }
        return result;
    }
};
//-----------------------------------------------------------------------------------------------------------------
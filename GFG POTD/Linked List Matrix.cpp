/*
GFG Link       	       : https://www.geeksforgeeks.org/problems/linked-list-matrix/1
GFG Problem difficulty : Medium
GFG Related Topic      : Linked List, Data Structures
Medium Article Link    : 
*/

//------------------------------Solution - in - C++ -----------------------------------------------------------

//Approach 1 : Brute Force
//T.C        : O(n^2)
//S.C        : O(n^2)
//------------------------------------------------------------------------------------------------------------------
class Solution {
  public:
    Node* constructLinkedMatrix(vector<vector<int>>& mat) {
        // code Here
        int n=mat.size();
        
        vector<vector<Node*>>nodeMat(n, vector<Node*>(n, NULL));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                nodeMat[i][j]=new Node(mat[i][j]);
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(j<n-1){
                    nodeMat[i][j]->right=nodeMat[i][j+1];
                }
                if(i<n-1){
                    nodeMat[i][j]->down=nodeMat[i+1][j];
                }
            }
        }
        return nodeMat[0][0];
    }
};
//------------------------------------------------------------------------------------------------------------------
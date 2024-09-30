/*
GFG Link               : https://www.geeksforgeeks.org/problems/merge-two-bst-s/1
GFG Problem difficulty : Medium
GFG Related Topic      : Binary Search Tree, Tree, DSA
Medium Article Link    : 
*/

//------------------------------Solution - in - C++ -----------------------------------------------------------

//Approach 1 : Brute Force
//T.C        : O((n+m)*log(n+m))
//S.C        : O(height if the BST1+BST2+m+n)
//------------------------------------------------------------------------------------------------------------------
class Solution {
  public:
    // Function to return a list of integers denoting the node
    // values of both the BST in a sorted order.
    
    void Inorder(Node* root, vector<int>& result){
        if(!root){
            return;
        }
        
        Inorder(root->left, result);
        result.push_back(root->data);
        Inorder(root->right, result);
    }
    vector<int> merge(Node *root1, Node *root2) {
        // Your code here
        vector<int>result;
        Inorder(root1, result);
        Inorder(root2, result);
        sort(result.begin(), result.end());
        return result;
    }
};
//------------------------------------------------------------------------------------------------------------------

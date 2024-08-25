/*
Leetcode Link               : https://leetcode.com/problems/binary-tree-postorder-traversal/
Leetcode difficulty         : Easy
Leetcode Related Topic      : Stack, Tree, Depth-first-tree, Binary Tree, 
*/

//------------------------------Solution - in - C++ -----------------------------------------------------------

//Approach 1: Recursive Approach
//T.C       : O(n) 
//S.C       : O(n) 
//-------------------------------------------------------------------------------------------------------------

class Solution {
public:
    void solve(TreeNode* root, vector<int>& result){
        if(root==NULL){
            return;
        }
        solve(root->left, result);
        solve(root->right, result);
        result.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        solve(root, result);
        return result;
    }
};

//--------------------------------------------------------------------------------------------------------------

//Approach 2: Iterative Approach using Two Stacks
//T.C       :O(n)
//S.C       :O(n)
//--------------------------------------------------------------------------------------------------------------

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if (root == nullptr) return {};
        
        vector<int> result;
        stack<TreeNode*> s1, s2;
        s1.push(root);
        
        while (!s1.empty()) {
            TreeNode* node = s1.top();
            s1.pop();
            s2.push(node);
            
            if (node->left) s1.push(node->left);
            if (node->right) s1.push(node->right);
        }
        
        while (!s2.empty()) {
            result.push_back(s2.top()->val);
            s2.pop();
        }
        
        return result;
    }
};

//--------------------------------------------------------------------------------------------------------------
//Approach 3: Iterative Approach using One Stack
//T.C       :O(n)
//S.C       :O(n)
//--------------------------------------------------------------------------------------------------------------

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
       vector<int> result;
        stack<TreeNode*> st;
        TreeNode* lastVisited = nullptr;
        
        while (!st.empty() || root != nullptr) {
            if (root != nullptr) {
                st.push(root);
                root = root->left;
            } else {
                TreeNode* peekNode = st.top();
                if (peekNode->right != nullptr && lastVisited != peekNode->right) {
                    root = peekNode->right;
                } else {
                    result.push_back(peekNode->val);
                    lastVisited = peekNode;
                    st.pop();
                }
            }
        }
        
        return result;
    
    }
};

//--------------------------------------------------------------------------------------------------------------


/*
Leetcode Link               : https://leetcode.com/problems/linked-list-in-binary-tree/
Leetcode difficulty         : Medium
Leetcode Related Topic      : Linked List, Tree, Depth-Forst-Search, Breadth-First Search, Binary Tree
*/

//------------------------------Solution - in - C++ -----------------------------------------------------------

//Approach 1: DFS 
//T.C       : O(n+m) check(m)
//S.C       : O(n+m)
//-------------------------------------------------------------------------------------------------------------

class Solution {
public:
    bool check(ListNode* head, TreeNode* root){
        if(head==NULL){
            return true;
        }
        
        if(root==nullptr ||head->val != root->val){
            return false;
        }
        
        return check(head->next, root->left) || check(head->next, root->right);
        
    }
    
    bool isSubPath(ListNode* head, TreeNode* root) {
        if(root==NULL){
            return false;
        }
        
        return check(head, root) || isSubPath(head, root->left) || isSubPath(head, root->right);
    }
};

//----------------------------------------------------------------------------------------------------------
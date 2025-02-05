// GFG Link               : https://www.geeksforgeeks.org/problems/mirror-tree/1
// GFG Problem difficulty : Easy
// GFG Related Topic      : Tree
// ------------------------------Solution - in - C++ -----------------------------------------------------------
// Approach 1 : Recursive DFS
// T.C        : O(n)
// S.C        : O(h)
//--------------------------------------------------------------------------------------------------------------
class Solution {
public:
    void mirrorTree(Node* root) {
        if (!root) return;

        // Swap left and right children
        swap(root->left, root->right);

        // Recur for left and right subtrees
        mirrorTree(root->left);
        mirrorTree(root->right);
    }

    void inorder(Node* root) {
        if (!root) return;
        inorder(root->left);
        cout << root->val << " ";
        inorder(root->right);
    }
};
//--------------------------------------------------------------------------------------------------------------
// Approach 2 : Iterative BFS (Level Order)
// T.C        : O(n)
// S.C        : O(n)
//--------------------------------------------------------------------------------------------------------------
class Solution {
public:
    void mirrorTree(Node* root) {
        if (!root) return;

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* node = q.front();
            q.pop();

            // Swap left and right
            swap(node->left, node->right);

            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
    }
//--------------------------------------------------------------------------------------------------------------
// Approach 3 : Iterative DFS (Using Stack)
// T.C        : O(n)
// S.C        : O(h)
//--------------------------------------------------------------------------------------------------------------
class Solution {
public:
    void mirrorTree(Node* root) {
        if (!root) return;

        stack<Node*> st;
        st.push(root);

        while (!st.empty()) {
            Node* node = st.top();
            st.pop();

            // Swap left and right children
            swap(node->left, node->right);

            if (node->left) st.push(node->left);
            if (node->right) st.push(node->right);
        }
    }
};
//--------------------------------------------------------------------------------------------------------------

/*
GFG Link               : https://www.geeksforgeeks.org/problems/height-of-binary-tree/1
GFG Problem difficulty : Easy
GFG Related Topic      : Tree
*/
//------------------------------Solution - in - C++ -----------------------------------------------------------
//Approach 1 : BFS
//T.C        : O(n)
//S.C        : O(n)
//--------------------------------------------------------------------------------------------------------------
class Solution {
  public:
    // Function to find the height of a binary tree.
    int height(Node* node) {
        // code here
        if(!node) return -1;
        
        queue<Node*>que;
        que.push(node);
        int height=-1;
        
        while(!que.empty()){
            int levelSize=que.size();
            height++;
            
            for(int i=0; i<levelSize; i++){
                Node* temp=que.front();
                que.pop();
                
                if(temp->left){
                    que.push(temp->left);
                }
                if(temp->right){
                    que.push(temp->right);
                }
            }
        }
        return height;
    }
};
//--------------------------------------------------------------------------------------------------------------
//Approach 2 : DFS
//T.C        : O(n)
//S.C        : O(n)
//--------------------------------------------------------------------------------------------------------------
class Solution {
  public:
    // Function to find the height of a binary tree.
    int height(Node* node) {
        // code here
        if(!node) return -1;
        
        int leftHeight=height(node->left);
        int rightHeight=height(node->right);

        return max(leftHeight, rightHeight)+1;
    }
};

// GFG Practice Problem      : https://practice.geeksforgeeks.org/problems/detect-loop-in-linked-list/1
// GFG Problem difficulty    : Easy
// GFG related topics        : Trees
//------------------------------------------------------------------------------
class Solution {
  public:
    vector<vector<int>> levelOrder(Node *root) {
        // Your code here
        vector<vector<int>>result;
        
        queue<Node*>que;
        que.push(root);
        
        while(!que.empty()){
            vector<int>level;
            int levelSize=que.size();
            
            for(int i=0; i<levelSize; i++){
                Node* front=que.front();
                que.pop();
                level.push_back(front->data);
                
                if(front->left){
                    que.push(front->left);
                }
                if(front->right){
                    que.push(front->right);
                }
            }
            result.push_back(level);
        }
        return result;
    }
};
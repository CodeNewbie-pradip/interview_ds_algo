/*
Leetcode Link               : https://leetcode.com/problems/spiral-matrix-iv/
Leetcode difficulty         : Medium
Leetcode Related Topic      : Arrays    Linked List     Matrix  Simulation
*/

//------------------------------Solution - in - C++ -----------------------------------------------------------

//Approach 1: Simulating Spiral Traversal
//T.C       : O(m*n)
//S.C       : O(m*n)
//-------------------------------------------------------------------------------------------------------------
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m, vector<int>(n, -1));
        ListNode* curr=head;
        int top=0, left=0, right=n-1, bottom=m-1;
        
        while(top<=bottom && left<=right){
            for(int i=left; i<=right && curr !=NULL; i++){
                ans[top][i]=curr->val;
                curr=curr->next;
            }
            top++;
            
            for(int i=top; i<=bottom && curr !=NULL; i++){
                ans[i][right]=curr->val;
                curr=curr->next;
            }
            right--;
            
            for(int i=right; i>=left && curr !=NULL; i--){
                ans[bottom][i]=curr->val;
                curr=curr->next;
            }
            bottom--;
            
            if(left<=right){
                for(int i=bottom; i>=top && curr !=NULL; i--){
                    ans[i][left]=curr->val;
                    curr=curr->next;
                }
                left++;
            }
        }
        return ans;
    }
};
//-------------------------------------------------------------------------------------------------------------
//Approach 2: Using Direction Array for Spiral Traversal 
//T.C       : O(m*n)
//S.C       : O(m*n)
//-------------------------------------------------------------------------------------------------------------
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> matrix(m, vector<int>(n, -1)); // Initialize matrix
        
        int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; // Right, Down, Left, Up
        int dir = 0; // Start with direction "right"
        int x = 0, y = 0; // Starting position
        
        ListNode* curr = head;
        
        for (int i = 0; i < m * n && curr != nullptr; i++) {
            matrix[x][y] = curr->val;
            curr = curr->next;
            
            int nextX = x + directions[dir][0];
            int nextY = y + directions[dir][1];
            
            // Check if next cell is out of bounds or already filled
            if (nextX < 0 || nextX >= m || nextY < 0 || nextY >= n || matrix[nextX][nextY] != -1) {
                dir = (dir + 1) % 4; // Change direction
                nextX = x + directions[dir][0];
                nextY = y + directions[dir][1];
            }
            
            x = nextX;
            y = nextY;
        }
        
        return matrix;
    }
};

//-------------------------------------------------------------------------------------------------------------------

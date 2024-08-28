/*
Leetcode Link               : https://leetcode.com/problems/count-sub-islands/
Leetcode difficulty         : Medium
Leetcode Related Topic      : Array, Matrix, Breadth-First-search, Depth-first-search, union Find
*/

//------------------------------Solution - in - C++ -----------------------------------------------------------

//Approach 1: DFS
//T.C       : O(m*n) 
//S.C       : O(m*n) 
//-------------------------------------------------------------------------------------------------------------
class Solution {
public:
    int m, n;
    
    bool dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i, int j) {
        // If out of bounds or water, return true (because we're interested in land cells)
        if (i < 0 || i >= m || j < 0 || j >= n || grid2[i][j] == 0) {
            return true;
        }
        
        // If this part of grid2 is land but not land in grid1, it's not a sub-island
        if (grid1[i][j] == 0) {
            return false;
        }
        
        // Mark this cell as visited in grid2
        grid2[i][j] = 0;
        
        // Recursively check all 4 directions
        bool isSubIsland = true;
        isSubIsland &= dfs(grid1, grid2, i - 1, j); // up
        isSubIsland &= dfs(grid1, grid2, i + 1, j); // down
        isSubIsland &= dfs(grid1, grid2, i, j - 1); // left
        isSubIsland &= dfs(grid1, grid2, i, j + 1); // right
        
        return isSubIsland;
    }
    
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        m = grid1.size();
        n = grid1[0].size();
        int subIslandCount = 0;
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid2[i][j] == 1) {
                    // If dfs returns true, it's a sub-island
                    if (dfs(grid1, grid2, i, j)) {
                        subIslandCount++;
                    }
                }
            }
        }
        
        return subIslandCount;
    }
};

//----------------------------------------------------------------------------------------------------------------

//Approach 2: BFS
//T.C       : O(m*n) 
//S.C       : O(m*n) 
//-------------------------------------------------------------------------------------------------------------

class Solution {
public:
    vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}}; //down, up, right , left
    bool isLands(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i, int j){
        int m = grid1.size();
        int n = grid1[0].size();

        bool result = true;

        queue<pair<int, int>> que; //{i, j} //BFS me we use queue
        que.push({i, j});
        grid2[i][j] = -1; //mark visited

        while(!que.empty()) {
            auto [x, y] = que.front();
            que.pop();

            if(grid1[x][y] != 1) { //grid1 must have 1 at that same co-ordinate
                result = false;
            }

            for(vector<int>& dir : directions) {
                int newX = x + dir[0];
                int newY = y + dir[1];

                if(newX >= 0 && newX < m && newY >= 0 && newY < n && grid2[newX][newY] == 1) {
                    grid2[newX][newY] = -1; //mark visited
                    que.push({newX, newY});
                }
            }
        }

        return result;
    }
    
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int result=0;
        int n=grid2.size();
        int m=grid2[0].size();
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid2[i][j]==1 && isLands(grid1, grid2, i, j)){
                    result++;
                }
            }
        }
        return result;
    }
};

//----------------------------------------------------------------------------------------------------------------
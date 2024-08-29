class Solution {
public:
    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};
    vector<vector<int>> vis;
    bool valid = true;

    bool canMove(int x, int y, int limit_x, int limit_y) {
        if (x >= 0 && x < limit_x && y >= 0 && y < limit_y) {
            return true;
        }
        return false;
    }

    void dfs(int x, int y, vector<vector<int>>& grid1,vector<vector<int>>& grid2) {
        vis[x][y] = 1 ; 
       
        if(!grid1[x][y]){
            valid = false;
        }
        for(int i = 0 ;i <4 ; i++){
            int xx = x + dx[i];
            int yy = y + dy[i];
            if( canMove(xx,yy,grid1.size(),grid1[0].size()) && !vis[xx][yy] && grid2[xx][yy]!=0){
                dfs( xx, yy, grid1, grid2);
            } 
        }
    }

    int countSubIslands(vector<vector<int>>& grid1,vector<vector<int>>& grid2) {
        int n = grid1.size();
        int m = grid1[0].size();
        int ans = 0 ; 
        vis.assign(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(!vis[i][j] && grid2[i][j]!=0){
                    valid = true; 
                    dfs(i,j,grid1,grid2); 
                    ans+= (valid ? 1 : 0 );
                }
            }
        }
        return ans;
    }
};

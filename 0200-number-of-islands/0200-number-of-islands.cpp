class Solution {
public:
    vector<int> dx = {0, 1, 0, -1};
    vector<int> dy = {1, 0, -1, 0};
    vector<vector<bool>> vis ; 
    char zero = '0' ; 
    bool canMove(int x, int y, int limit_x, int limit_y) {
        if (x >= 0 && x < limit_x && y >= 0 && y < limit_y) {
            return true;
        }
        return false;
    }

    void dfs(int i , int j , vector<vector<char>>& grid){
        vis[i][j] = true; 
        for(int k = 0 ; k < 4 ; k++){
            int x = i + dx[k];
            int y = j + dy[k];
            if(canMove(x,y,grid.size(),grid[0].size()) && !vis[x][y] && grid[x][y] != zero){
                dfs(x,y,grid);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(); 
        int m = grid[0].size(); 
        int ans = 0 ; 
        vis.assign(n, vector<bool>(m, false));
        for(int i = 0 ;i<n;i++){
            for(int j = 0 ;j<m;j++){
                if(!vis[i][j] && grid[i][j] != zero){
                    ans++;
                    dfs(i,j,grid);
                }
            }   
        }
        return ans;
    }
};
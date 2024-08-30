class Solution {
public:
    vector<int> dx = {0, 1, 0, -1};
    vector<int> dy = {1, 0, -1, 0};
    vector<vector<bool>> vis;
    int max_area = -1, current_area = 0;

    bool canMove(int x, int y, int limit_x, int limit_y) {
        return x >= 0 && x < limit_x && y >= 0 && y < limit_y;
    }

    void dfs(int i, int j, vector<vector<int>>& grid) {
        current_area++;
        cout << current_area << endl;
        max_area = max(max_area, current_area);
        vis[i][j] = true;
        for (int k = 0; k < 4; k++) {
            int x = i + dx[k];
            int y = j + dy[k];
            if (canMove(x, y, grid.size(), grid[0].size()) && !vis[x][y] &&
                grid[x][y] == 1) {
                dfs(x, y, grid);
            }
        }
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        vis.assign(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                current_area = 0;
                if (!vis[i][j] && grid[i][j] == 1) {
                    dfs(i, j, grid);
                }
            }
        }
        return max_area == -1 ? 0 : max_area;
    }
};
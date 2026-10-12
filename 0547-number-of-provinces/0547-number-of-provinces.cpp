class Solution {
    int res = 0;

   void dfs(vector<vector<int>>& grid, int i, int n,
         vector<bool>& vis) {
    vis[i] = true;

    for (int j = 0; j < n; j++) {
        if (grid[i][j] == 1 && !vis[j]) {
            dfs(grid, j, n, vis);
        }
    }
}


public:
    int findCircleNum(vector<vector<int>>& grid) {
    int n = grid.size();
    vector<bool> vis(n, false);
    int res = 0;

    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            dfs(grid, i, n, vis);
            res++;
        }
    }

    return res;
}
};
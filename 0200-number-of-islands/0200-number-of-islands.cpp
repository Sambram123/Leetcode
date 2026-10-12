class Solution {
    int res = 0;
    int x[4] = {-1,1,0,0};
    int y[4] = {0,0,-1,1};

    bool isValid(int i,int j,int n,int m){
        if(i<0 || i>=n || j<0 || j>=m)
            return false;

        return true;
    }

    void dfs(vector<vector<char>>& grid,int i,int j,vector<vector<bool>>& vis,int n,int m){
        if(grid[i][j]=='0') return;
        vis[i][j] = true;

        for(int k=0;k<4;k++){
            int row = i+x[k];
            int col = j+y[k];

            if(isValid(row,col,n,m) && vis[row][col]==false)
                 dfs(grid,row,col,vis,n,m);
        }
        return;
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
       vector<vector<bool>> vis(n, vector<bool>(m, false));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && vis[i][j]==false){
                    dfs(grid,i,j,vis,n,m);
                    res++;
                }
            }
        }

        return res;
    }
};
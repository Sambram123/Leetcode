class Solution {
    int x[4] = {-1,1,0,0};
    int y[4] = {0,0,-1,1};

    bool isValid(int i,int j,int n,int m){
        if(i<0 || j<0 || i>=n || j>=m)
            return false;
        
        return true;
    }

    void dfs(vector<vector<int>>& grid,int i,int j,int n,int m,vector<vector<int>>& vis,long long& sum){
        vis[i][j]=1;
        sum+=grid[i][j];

        for(int k=0;k<4;k++){
            int row = i+x[k];
            int col = j+y[k];

            if(isValid(row,col,n,m) && vis[row][col]==0 && grid[row][col]!=0){
                dfs(grid,row,col,n,m,vis,sum);
            }
        }
        return;
    }
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        long long res = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                long long sum = 0;
                if(grid[i][j]!=0 && vis[i][j]==0){
                    dfs(grid,i,j,n,m,vis,sum);
                    if(sum%k == 0){
                        res+=1;
                    }
                }
            }
        }
        return res;
    }
};
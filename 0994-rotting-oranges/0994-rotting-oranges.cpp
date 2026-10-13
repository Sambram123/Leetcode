class Solution {
    bool isValid(int i,int j,int n,int m){
        if(i<0 || i>=n || j<0 || j>=m)
            return false;
        
        return true;
    }
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int time = 0;
        int fresh = 0;

        queue<pair<int,int>> q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1)
                    fresh++;
                if(grid[i][j]==2){
                    q.push({i,j});
                    grid[i][j]=-1;
                }
                    
            }
        }

        int x[4] = {-1,1,0,0};
        int y[4] = {0,0,-1,1};

        while(!q.empty() && fresh>0){
            time++;
            int s = q.size();
            while(s--){
                pair<int,int> p = q.front();
                int i = p.first;
                int j = p.second;
                q.pop();


                for(int k=0;k<4;k++){
                    int row = i + x[k];
                    int col = j + y[k];

                    if(isValid(row,col,n,m) && grid[row][col]==1){
                        q.push({row,col});
                        fresh--;
                        grid[row][col] = -1;
                    }       
                }  
            }
        }

        if(fresh>0)
            return -1;

        return time;
    }
};
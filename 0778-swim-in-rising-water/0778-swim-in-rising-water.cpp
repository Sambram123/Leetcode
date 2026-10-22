class Solution {
    bool isValid(int i,int j,int n,int m){
        if(i<0 || j<0 || i>=n || j>=m)
            return false;
        
        return true;
    }
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        priority_queue<pair<int,pair<int,int>>,
                    vector<pair<int,pair<int,int>>>,
                    greater<>> pq;
        vector<vector<int>> cost(n,vector<int>(m,INT_MAX));
        cost[0][0] = grid[0][0];
        pq.push({cost[0][0],{0,0}});

        int x[4] = {-1,1,0,0};
        int y[4] = {0,0,-1,1};

        while(!pq.empty()){
            auto p = pq.top();
            pq.pop();

            int c = p.first;
            int i = p.second.first;
            int j = p.second.second;

            for(int k=0;k<4;k++){
                int row = i+x[k];
                int col = j+y[k];

                if(!isValid(row,col,n,m))
                    continue;
                
                int newCost = max(c,grid[row][col]);
                
                if(newCost < cost[row][col]){
                    cost[row][col] = newCost;
                     pq.push({newCost,{row,col}});
                }  
            }
        }
        return cost[n-1][m-1];
    }
};
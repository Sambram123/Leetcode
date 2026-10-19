class Solution {
    int x[4] = {-1,1,0,0};
    int y[4] = {0,0,-1,1};

    bool isValid(int i,int j,int n,int m){
        if(i<0 || i>=n || j<0 || j>=m)
            return false;
        
        return true;
    }
public:
    int minimumEffortPath(vector<vector<int>>& a) {
        int n = a.size();
        int m = a[0].size();

        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
        priority_queue<pair<int,pair<int,int>>,
            vector<pair<int,pair<int,int>>>,
            greater<>> pq;

        dist[0][0] = 0;
        pq.push({0,{0,0}});

        while(!pq.empty()){
            pair<int,pair<int,int>> p = pq.top();
            pq.pop();

            int d = p.first;
            int i = p.second.first;
            int j = p.second.second;

            if(d > dist[i][j])
                continue;
        

        for(int k=0;k<4;k++){
            int row = i+x[k];
            int col = j+y[k];

            if(!isValid(row,col,n,m))
                continue;
            
            int maxAbsDiff = abs(a[row][col] - a[i][j]);
            int newDist = max(maxAbsDiff , d);

            if(newDist < dist[row][col]){
                dist[row][col] = newDist;
                pq.push({newDist,{row,col}});
            }
        }
    }

        return dist[n-1][m-1];
        
    }
};
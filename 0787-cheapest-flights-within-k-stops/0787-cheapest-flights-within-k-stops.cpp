class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> res(n,INT_MAX);
        
        res[src] = 0;

        for(int i=0;i<=k;i++){
            vector<int> tmp = res;
            for(auto& edge : flights){
                int u = edge[0];
                int v = edge[1];
                int w = edge[2];

                if(res[u]!=INT_MAX && res[u]+w < tmp[v])
                    tmp[v] = res[u]+w;
            }
            res = tmp;
        }
        
        if(res[dst]==INT_MAX)
            return -1;
        
        return res[dst];
    }
};
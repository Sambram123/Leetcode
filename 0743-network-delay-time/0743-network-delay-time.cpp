class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto edge : times){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            adj[u].push_back({v,w});
        }

        priority_queue<pair<int,int>,
               vector<pair<int,int>>,
               greater<pair<int,int>>> pq; 
    

        vector<int> dist(n+1,INT_MAX);

        dist[k]=0;
        pq.push({0,k});

        while(!pq.empty()){
            pair<int,int> p = pq.top();
            pq.pop();

            int d = p.first;
            int node = p.second;

            for(auto neighbour : adj[node]){
                int neigh = neighbour.first;
                int wt = neighbour.second;

                if(d+wt < dist[neigh]){
                    dist[neigh] = d+wt;
                    pq.push({dist[neigh],neigh});
                }
            }
        }
        
        int res = *max_element(dist.begin()+1,dist.end());

        if(res==INT_MAX) return -1;

        return res;
    }
};
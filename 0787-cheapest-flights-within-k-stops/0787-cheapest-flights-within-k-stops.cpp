class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);

        for(int i=0;i<flights.size();i++){
            int s=flights[i][0];
            int d=flights[i][1];
            int w=flights[i][2];
            adj[s].push_back({d,w});
        }
        
        queue<pair<int,pair<int,int>>>q; 
        vector<int>dist(n,1e9);

        // stops, node, dist
        q.push({0,{src,0}});
        dist[src]=0;

        while(!q.empty()){
            auto node=q.front();
            q.pop();
            int s=node.first;
            int dest=node.second.first;
            int d=node.second.second;

            if(s>k)continue;

            for(auto it:adj[dest]){
                int targetn=it.first;
                int cost=it.second;

                if((s+1) <=k+1 && (cost+d)<dist[targetn]){
                    q.push({s+1,{targetn,cost+d}});
                    dist[targetn]=cost+d;
                }
            }
        }
        if(dist[dst]!=1e9)return dist[dst];
        return -1;



    }
};
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n);
        int MOD = 1e9+7;

        for(auto &node : roads){
            int u = node[0];
            int v = node[1];
            int time = node[2];
            adj[u].push_back({v, time});
            adj[v].push_back({u, time});
        }

        priority_queue<pair<long long,int>,
            vector<pair<long long,int>>,
            greater<pair<long long,int>>> q;

        vector<long long> dist(n, LLONG_MAX);
        vector<long long> ways(n, 0);

        dist[0] = 0;
        ways[0] = 1;
        q.push({0,0});

        while(!q.empty()){
            auto node = q.top();
            q.pop();

            long long c = node.first;
            int u = node.second;

         

            for(auto it : adj[u]){
                int v = it.first;
                int cost = it.second;
                long long newDist = c + cost;

                if(newDist < dist[v]){
                    dist[v] = newDist;
                    ways[v] = ways[u];
                    q.push({newDist, v});
                }
                else if(newDist == dist[v]){
                    ways[v] = (ways[v] + ways[u]) % MOD;
                }
            }
        }

        return ways[n-1] % MOD;
    }
};

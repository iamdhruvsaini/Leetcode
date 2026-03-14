class Solution {
public:
    bool dfs(vector<vector<int>>& graph, vector<int>& vis, int node){
        for(auto it : graph[node]){
            if(vis[it] == -1){
                vis[it] = !vis[node];
                if(!dfs(graph, vis, it)) return false;
            }
            else{
                if(vis[it] == vis[node]) return false;
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n, -1);

        for(int i = 0; i < n; i++){
            if(vis[i] == -1){
                vis[i] = 0;   // assign initial color
                if(!dfs(graph, vis, i)) return false;
            }
        }

        return true;
    }
};
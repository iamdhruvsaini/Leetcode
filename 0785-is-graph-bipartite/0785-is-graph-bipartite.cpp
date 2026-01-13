class Solution {
public:
    bool dfs(int node,int clr,vector<vector<int>>& graph,vector<int> &vis){
        vis[node]=clr;

        for(auto it: graph[node]){
            if(vis[it]==-1){
               if (!dfs(it, !clr, graph, vis)) {
                    return false;
                }
            }
            else if(vis[it]==vis[node]){
                return false;

            }
        }

        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n, -1);  // -1 = uncolored, 0 and 1 are two colors

        for(int i = 0; i < n; i++) {
            if(vis[i] == -1 && dfs(i,1,graph,vis)==false) {
                return false;
                
            }
        }
        return true;
    }
};

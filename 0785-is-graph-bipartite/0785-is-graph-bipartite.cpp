class Solution {
public:
    bool checkBipartite(int  start,vector<vector<int>>& graph, vector<int>&vis){

        queue<int>q;
        q.push(start);
        vis[start]=1;

        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto adj: graph[node]){
                if(vis[adj]==-1){
                    vis[adj]=!vis[node];
                    q.push(adj);
                }
                else if(vis[adj]==vis[node]){
                    return false;
                }
            }
        }

        return true;

    }
    bool isBipartite(vector<vector<int>>& graph) {
        int v=graph.size();
        vector<int>vis(v,-1);

        for(int i=0;i<v;i++){
            if(vis[i]==-1){
                bool ch= checkBipartite(i,graph,vis);
                if(ch==false)return false;
            }
        }

        return true;
        
    }
};
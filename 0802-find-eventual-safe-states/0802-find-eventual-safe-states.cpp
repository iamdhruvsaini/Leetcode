class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
            
            int nodeCnt=graph.size();
            vector<vector<int>>adj(nodeCnt);

            for(int i=0;i<nodeCnt;i++){
                for(auto node: graph[i]){
                    adj[node].push_back(i);
                }
            }

            // find the toposort by dfs or bfs
            queue<int>q;

            vector<int>indegree(nodeCnt,0);
            for(int i=0;i<nodeCnt;i++){
                for(auto node : adj[i]){
                    indegree[node]++;
                }
            }

            for(int i=0;i<nodeCnt;i++){
                if(indegree[i]==0){
                    q.push(i);
                }
            }
            vector<int>ans;
            while(!q.empty()){
                int node=q.front();
                ans.push_back(node);
                q.pop();
                for(auto i: adj[node]){
                    indegree[i]--;
                    if(indegree[i]==0){
                        q.push(i);
                    }
                }
            }
            sort(ans.begin(),ans.end());
            return ans;

    }

};
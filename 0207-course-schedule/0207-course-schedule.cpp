class Solution {
public:
    bool canFinish(int num, vector<vector<int>>& prereq) {

        vector<vector<int>>adj(num);

        for(int i=0;i<prereq.size();i++){
            int c=prereq[i][0];
            int req=prereq[i][1];
            adj[c].push_back(req);
        }

        vector<int>indegree(num,0);
        for(int i=0;i<num;i++){
            for(auto node : adj[i]){
                indegree[node]++;
            }
        }


        queue<int>q;
        for(int i=0;i<num;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<int>temp;
        while(!q.empty()){
            int top=q.front();
            temp.push_back(top);
            q.pop();
            for(auto i: adj[top]){
                indegree[i]--;
                if(indegree[i]==0){
                    q.push(i);
                }
            }
        }


        if(temp.size()==num)return 1;
        return 0;

    }
};
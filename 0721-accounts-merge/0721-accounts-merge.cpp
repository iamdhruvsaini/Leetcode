class DisjointSet{
    public:
    vector<int>parent,rank;
    DisjointSet(int n){
        parent.resize(n,0);
        rank.resize(n,0);
        for(int i=0;i<n;i++)parent[i]=i;
    }

    int ultimateParent(int u){
        if(parent[u]==u)return u;
        return parent[u]=ultimateParent(parent[u]);
    }

    bool checkComponent(int u,int v){
        return ultimateParent(u)==ultimateParent(v);
    }

    void unionByRank(int u,int v){
        int ulp_u=ultimateParent(u);
        int ulp_v=ultimateParent(v);

        if(ulp_u==ulp_v)return;

        if(rank[ulp_u]<rank[ulp_v]){
            parent[ulp_u]=ulp_v;
        }
        else if(rank[ulp_v]<rank[ulp_u]){
            parent[ulp_v]=ulp_u;
        }
        else{
            // same rank
            parent[ulp_u]=ulp_v;
            rank[ulp_v]++;
        }
    }
};

class Solution {
public:
    
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        
        unordered_map<string,int>mp;
        int n=accounts.size();
        DisjointSet ds(n);
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                if(mp.find(accounts[i][j])==mp.end()){
                    // not exist
                    mp[accounts[i][j]]=i;
                }
                else{
                    // already present then this and that are same component
                    ds.unionByRank(i, mp[accounts[i][j]]);
                }
            }
        }

        vector<vector<string>> vec(n);

        for(auto it:mp){
            string s=it.first;
            int node=it.second;
            int ulp_node=ds.ultimateParent(node);
            vec[ulp_node].push_back(s);
        }

        vector<vector<string>>ans;

        for(int i=0;i<n;i++){
            if(vec[i].empty()){
                continue;
            }
            vector<string>t;
            t.push_back(accounts[i][0]);
            sort(vec[i].begin(),vec[i].end());
            for(auto it:vec[i]){
                t.push_back(it);
            }
            ans.push_back(t);
        }
        return ans;

        
    }
};
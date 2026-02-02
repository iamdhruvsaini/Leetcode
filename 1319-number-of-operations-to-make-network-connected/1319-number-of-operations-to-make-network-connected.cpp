class Solution {
public:
    class DisjointSet{
        public:
        vector<int>rank,parent;

        DisjointSet(int n){
            rank.resize(n,0);
            parent.resize(n,0);
            for(int i=0;i<n;i++)parent[i]=i;
        }

        int findUltimateParent(int u){
            if(parent[u]==u)return u;

            return parent[u]=findUltimateParent(parent[u]);
        }

        bool checkComponent(int u,int v){
            return findUltimateParent(u)==findUltimateParent(v);
        }

        void unionByRank(int u,int v){
            int ulp_u=findUltimateParent(u);
            int ulp_v=findUltimateParent(v);

            if(rank[ulp_u]<rank[ulp_v]){
                parent[ulp_u]=ulp_v;
            }
            else if(rank[ulp_v]<rank[ulp_u]){
                parent[ulp_v]=ulp_u;
            }else{
                parent[ulp_u]=ulp_v;
                rank[ulp_v]++;
            }
        }

    };
    int makeConnected(int n, vector<vector<int>>& connections) {

        DisjointSet dsu(n);

        // Find the extra nodes

        int cnt=0;
        for(int i=0;i<connections.size();i++){
            int u=connections[i][0];
            int v=connections[i][1];
            if(dsu.checkComponent(u,v)){
                // They belong to same component so an extra edge
                cnt++;
            }
            else{
                dsu.unionByRank(u,v);
            }
        }

        //Now check for the num of component
        int comp=0;
        for(int i=0;i<n;i++){
            if(dsu.parent[i]==i){
                comp++;
            }
        }

        if(cnt>=comp-1){
            return comp-1;
        }
        return -1;




        

    }
};
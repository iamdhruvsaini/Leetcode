class Solution {
public:
    class DisjointSet{
        public:
        vector<int>parent,rank;
        DisjointSet(int n){
            parent.resize(n+1,0);
            rank.resize(n+1,0);

            for(int i=0;i<=n;i++){
                parent[i]=i;
            }
        }
        
        int findUltimateParent(int u){
            if(parent[u]==u)return u;

            return parent[u]=findUltimateParent(parent[u]);
        }


        bool sameComponent(int u,int v){
            int ul_u=findUltimateParent(u);
            int ul_v=findUltimateParent(v);
            return ul_u==ul_v;
        }

        int countParent(){
            int cnt=0;
            for(int i=0;i<parent.size();i++){
                if(parent[i]==i)cnt++;
            }
            return cnt;
        }

        void unionByRank(int u,int v){
            int ul_u=findUltimateParent(u);
            int ul_v=findUltimateParent(v);

            if(ul_u==ul_v)return;

            else if(rank[ul_u]<rank[ul_v]){
                parent[ul_u]=ul_v;
            }
            else if(rank[ul_v]<rank[ul_u]){
                parent[ul_v]=ul_u;
            }
            else{
                parent[ul_u]=ul_v;
                rank[ul_v]++;
            }
        }

    };
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet d(n);

        int extra=0;
        for(auto i:connections){
            int src=i[0];
            int dest=i[1];

            if(d.sameComponent(src,dest)){
               extra++; 
            }
            else{
                d.unionByRank(src,dest);
            }
        }

        int components = d.countParent()-1;
        int required = components - 1;

        if (extra >= required) return required;
        return -1;


    }
};
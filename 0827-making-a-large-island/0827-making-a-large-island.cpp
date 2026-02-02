class Solution {
public:
    class DisjointSet{
        public:
        vector<int>rank,parent,size;
        DisjointSet(int n){
            rank.resize(n,0);
            parent.resize(n);
            size.resize(n,1);
            for(int i=0;i<n;i++)parent[i]=i;
        }

        bool checkComponent(int u,int v){
            return findUltimateParent(u)==findUltimateParent(v);
        }

        int findUltimateParent(int u){
            if(parent[u]==u)return u;

            return parent[u]=findUltimateParent(parent[u]);
        }

        void unionByRank(int u,int v){
            int ulp_u=findUltimateParent(u);
            int ulp_v=findUltimateParent(v);

            if(ulp_u==ulp_v)return ;

            if(rank[ulp_u]<rank[ulp_v]){
                parent[ulp_u]=ulp_v;
            }
            else if(rank[ulp_v]<rank[ulp_u]){
                parent[ulp_v]=ulp_u;
            }else{
                // both have the same rank
                parent[ulp_u]=ulp_v;
                rank[ulp_v]++;
            }
        }

        void unionBySize(int u,int v){
            int ulp_u=findUltimateParent(u);
            int ulp_v=findUltimateParent(v);

            if(ulp_u==ulp_v)return;
            if(size[ulp_u]<size[ulp_v]){
                parent[ulp_u]=ulp_v;
                size[ulp_v]+=size[ulp_u];
            }
            else{
                parent[ulp_v]=ulp_u;
                size[ulp_u]+=size[ulp_v];
            }



        }
    };

    bool isValid(vector<vector<int>>& grid,int r,int c ){
        int n=grid.size();
        int m=grid[0].size();
        if(r>=0 && c>=0 && r<n && c<m)return 1;
        return 0;
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        DisjointSet dsu(n*m);
        int delr[]={-1,0,1,0};
        int delc[]={0,1,0,-1};
        

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0)continue;
                int cell=i*m+j;
                for(int k=0;k<4;k++){
                    int adjr=i+delr[k];
                    int adjc=j+delc[k];
                    int adjcell=adjr*m+adjc;
                    if(isValid(grid,adjr,adjc) && grid[adjr][adjc]==1){
                        dsu.unionBySize(cell,adjcell);
                    }
                }

            }
        }
        int maxi=0;
        for(int r=0;r<n;r++){
            for(int c=0;c<m;c++){
                int ans=1;
                if(grid[r][c]==1)continue;
                set<int>st;
                for(int k=0;k<4;k++){
                    int adjr=r+delr[k];
                    int adjc=c+delc[k];
                    int adjcell=adjr*m+adjc;
                    if(isValid(grid,adjr,adjc) && grid[adjr][adjc]==1){
                        st.insert(dsu.findUltimateParent(adjcell));
                    }
                }

                for(auto it:st){
                    ans+=dsu.size[it];
                }
                maxi=max(ans,maxi);
            }

        }

        // now check for the cell no also
        for(int cell=0;cell<n*m;cell++){
            maxi=max(maxi,dsu.size[cell]);
        }
        return maxi;
    }
};
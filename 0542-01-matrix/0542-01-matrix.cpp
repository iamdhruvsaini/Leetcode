class Solution {
public:
   
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

        int n=mat.size();
        int m=mat[0].size();

        vector<vector<int>>vis(n,vector<int>(m,0));
        vector<vector<int>>dis(n,vector<int>(m,0));


        queue<pair<pair<int,int>,int>>q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({{i,j},0});
                }
            }
        }

        int delr[]={-1,0,1,0};
        int delc[]={0,1,0,-1};
        while(!q.empty()){
            auto node=q.front();
            q.pop();
            int r=node.first.first;
            int c=node.first.second;
            int dist=node.second;
            dis[r][c]=dist;


           

            for(int i=0;i<4;i++){
                int nrow=delr[i]+r;
                int ncol=delc[i]+c;
                if(nrow>=0 && nrow<n 
                && ncol>=0 && ncol<m
                && !vis[nrow][ncol] && mat[nrow][ncol]==1){
                    q.push({{nrow,ncol},dist+1});
                    vis[nrow][ncol]=1;
                }
            }
        }
        

        return dis;
    }
};
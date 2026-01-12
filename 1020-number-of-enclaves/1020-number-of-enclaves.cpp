class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>>q;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<m;i++){
            if(grid[0][i]==1){
                q.push({0,i});
                vis[0][i]=1;
            }
            if(grid[n-1][i]==1){
                q.push({n-1,i});
                vis[n-1][i]=1;
            }
        }

        for(int i=1;i<n-1;i++){
            if(grid[i][0]==1){
                q.push({i,0});
                vis[i][0]=1;
            }
            if(grid[i][m-1]==1){
                q.push({i,m-1});
                vis[i][m-1]=1;
            }
        }

        int delr[]={1,0,-1,0};
        int delc[]={0,-1,0,1};

        while(!q.empty()){
            auto node=q.front();
            q.pop();
            int r=node.first;
            int c=node.second;

            for(int i=0;i<4;i++){
                int nr=r+delr[i];
                int nc=c+delc[i];

                if(nr>=0 && nr<n && nc>=0 && nc<m 
                    && !vis[nr][nc] && grid[nr][nc]==1){
                        q.push({nr,nc});
                        vis[nr][nc]=1;
                    }
            }

        }
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]==1){
                    cnt++;
                }
            }
        }
        return cnt;


        
    }
};
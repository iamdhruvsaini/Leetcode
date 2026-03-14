class Solution {
public:
    void bfs(vector<vector<char>>&grid,vector<vector<int>>&vis,int r,int c){
        queue<pair<int,int>>q;
        int n=grid.size();
        int m=grid[0].size();
        q.push({r,c});
        vis[r][c]=1;

        int delr[]={0,1,0,-1};
        int delc[]={-1,0,1,0};

        while(!q.empty()){
            auto node=q.front();
            q.pop();
            int r=node.first;
            int c=node.second;

            for(int i=0;i<4;i++){
                int newr=delr[i]+r;
                int newc=delc[i]+c;

                if(newr>=0 && newc>=0 && newr<n && newc<m
                 && grid[newr][newc]=='1' && !vis[newr][newc]){
                    q.push({newr,newc});
                    vis[newr][newc]=1;
                }
            }
            
        }

       
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j] == '1' ){
                    cnt++;
                    bfs(grid,vis,i,j);
                }
            }
        }
        return cnt;
    }
};
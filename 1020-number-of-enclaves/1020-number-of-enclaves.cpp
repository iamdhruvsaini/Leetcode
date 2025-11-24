class Solution {
public:
    void dfs(int r,int c,vector<vector<int>>&vis,vector<vector<int>>&grid){
        vis[r][c]=1;
        int n=grid.size();
        int m=grid[0].size();
        int delRow[]={-1,0,1,0};
        int delCol[]={0,1,0,-1};

        for(int i=0;i<4;i++){
            int row=delRow[i]+r;
            int col=delCol[i]+c;

            if(row>=0 && row<n && col>=0 && col<m
                && !vis[row][col] && grid[row][col]==1){
                    dfs(row,col,vis,grid);
                }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>>vis(n,vector<int>(m,0));
    

        for(int i=0;i<m;i++){
            if(grid[0][i]==1){
               dfs(0,i,vis,grid);
            }
            if(grid[n-1][i]==1){
               dfs(n-1,i,vis,grid);
            }
        }

         for(int i=0;i<n;i++){
            if(grid[i][0]==1){
               dfs(i,0,vis,grid);
            }
            if(grid[i][m-1]==1){
               dfs(i,m-1,vis,grid);
            }
        }

        // cnt=0;
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
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();

        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<int,int>>q;

        for(int c=0;c<m;c++){
            if(board[0][c]=='O'){
                q.push({0,c});
                vis[0][c]=1;
            }

            if(board[n-1][c]=='O'){
                q.push({n-1,c});
                vis[n-1][c]=1;
            }
        }

        for(int r=0;r<n;r++){
            if(board[r][0]=='O'){
                q.push({r,0});
                vis[r][0]=1;
            }
            if(board[r][m-1]=='O'){
                q.push({r,m-1});
                vis[r][m-1]=1;
            }
        }

        int delRow[]={-1,0,1,0};
        int delCol[]={0,1,0,-1};

        while(!q.empty()){
            auto p=q.front();
            q.pop();

            int r=p.first;
            int c=p.second;

            for(int i=0;i<4;i++){
                int nrow=r+delRow[i];
                int ncol=c+delCol[i];

                if(nrow>=0 && nrow<n 
                    && ncol>=0 && ncol<m 
                    && board[nrow][ncol]=='O' 
                    && !vis[nrow][ncol]
                ){
                    // board[n]
                    vis[nrow][ncol]=1;
                    q.push({nrow,ncol});
                }
            }

        }


        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==1){
                    board[i][j]='O';
                }
                else{
                    board[i][j]='X';
                }
            }
        }

  




    }
};
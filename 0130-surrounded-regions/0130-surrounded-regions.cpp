class Solution {
public:
    void solve(vector<vector<char>>& board) {

        queue<pair<int,int>>q;
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));

        for(int i=0;i<m;i++){
            if(board[0][i]=='O'){
                q.push({0,i});
                vis[0][i]=1;
            }
            if(board[n-1][i]=='O'){
                q.push({n-1,i});
                vis[n-1][i]=1;
            }
        }

        for(int i=1;i<n-1;i++){
            if(board[i][0]=='O'){
                q.push({i,0});
                vis[i][0]=1;
            }
            if(board[i][m-1]=='O'){
                q.push({i,m-1});
                vis[i][m-1]=1;
            }
        }

        int delr[]={-1,0,1,0};
        int delc[]={0,1,0,-1};

        while(!q.empty()){
            auto node=q.front();
            q.pop();

            int r=node.first;
            int c=node.second;

            for(int i=0;i<4;i++){
                int newr=delr[i]+r;
                int newc=delc[i]+c;
                if(newr >=0 && newr<n && newc>=0 && newc < m
                    && !vis[newr][newc] && board[newr][newc]=='O'){
                        q.push({newr,newc});
                        vis[newr][newc]=1;
                    }
            }

        }


for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        if(board[i][j]=='O' && !vis[i][j]){
            board[i][j]='X';   // flip only surrounded O's
        }
    }
}

        return ;
    }
};
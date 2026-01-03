class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        /*
            1. store the r,c,t in queue
            2. now visited[n][m] and store the already rotten in the queue
            3. pop each and mark the neigbour rotten if not and push it in the queue with inc time
            4. check if any orange is fresh but not marked visited then return -1 else return time 
        */
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));    
        queue<pair<int,pair<int,int>>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,{j,0}});
                    vis[i][j]=1;
                }
            }
        }

        // now perform bfs
        auto bfs=[&](){
            int time=0;
            while(!q.empty()){
                auto node=q.front();
                q.pop();
                int r=node.first;
                int c=node.second.first;
                int t=node.second.second;
                time=t;
            
                int delr[]={1,0,-1,0};
                int delc[]={0,-1,0,1};

                for(int i=0;i<4;i++){
                    int nr=r+delr[i];
                    int nc=c+delc[i];
                    if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc] && grid[nr][nc]==1){
                        vis[nr][nc]=1;
                        q.push({nr,{nc,t+1}});
                    }
                }
            }
            return time;
        };

        int time = bfs();

        // now check for the vis
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]==1){
                    return -1;
                }
            }
        }

        return time;

    }
};
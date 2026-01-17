class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0]!=0)return -1;

        int n=grid.size();
        vector<vector<int>>dist(n,vector<int>(n,1e9));

        priority_queue<
        pair<int,pair<int,int>>,
        vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>
        >pq;

        pq.push({0,{0,0}});
        dist[0][0]=0;

        
        int delr[]={-1,-1,0,1,1,1,0,-1};
        int delc[]={0,1,1,1,0,-1,-1,-1};

        while(!pq.empty()){

            auto node=pq.top();
            pq.pop();

            int cost=node.first;
            int r=node.second.first;
            int c=node.second.second;
            if(r==n-1 && c==n-1)return cost+1;

            for(int i=0;i<8;i++){
                int newr=r+delr[i];
                int newc=c+delc[i];


                if(newr>=0 && newc>=0 && newr<n && newc<n && grid[newr][newc]==0){
                    if(cost+1 < dist[newr][newc]){
                        dist[newr][newc]=cost+1;
                      
                        pq.push({cost+1,{newr,newc}});
                    }
                }

            }

            
        }

        return -1;
        
    }
};
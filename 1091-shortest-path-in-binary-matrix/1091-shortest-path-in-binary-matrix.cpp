class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        
        int n=grid.size();
        int m=grid[0].size();
        if(grid[0][0]==1){
            return -1;
        }

        if(n*m==1)return 1;
        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));

        priority_queue<
            pair<int,pair<int,int>>,
            vector<pair<int,pair<int,int>>>,
            greater<pair<int,pair<int,int>>>>pq;
        pq.push({1,{0,0}});
        dist[0][0]=1;

        int delr[]={0,1,1,1,0,-1,-1,-1};
        int delc[]={1,1,0,-1,-1,-1,0,1};



        while(!pq.empty()){

            auto top=pq.top();
            pq.pop();

            int d=top.first;
            int r=top.second.first;
            int c=top.second.second;

            for(int i=0;i<8;i++){

                int newr=delr[i]+r;
                int newc=delc[i]+c;

                if(newr >=0 && newr<n && newc >= 0 && newc<m
                && grid[newr][newc]!=1
                && d+1 < dist[newr][newc]
                ){
                    dist[newr][newc]=d+1;
                    pq.push({d+1,{newr,newc}});
                }

                if(newr==n-1 && newc==n-1 && grid[newr][newc]==0){
                    return dist[n-1][n-1];
                }

            }

        }


        return -1;

        
    }
};
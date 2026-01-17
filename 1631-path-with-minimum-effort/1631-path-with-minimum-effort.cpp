class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();

        // declaring the min heap
        priority_queue<
        pair<int,pair<int,int>>,
        vector< pair<int,pair<int,int>>>,
        greater< pair<int,pair<int,int>>>
        >pq;

        // it stores the diff
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        pq.push({0,{0,0}});
        dist[0][0]=0;
        int delr[]={-1,0,1,0};
        int delc[]={0,1,0,-1};
        while(!pq.empty()){
            auto node=pq.top();
            pq.pop();
            int diff=node.first;
            int r=node.second.first;
            int c=node.second.second;
            
            // now traverse the neighbour nodes
            for(int i=0;i<4;i++){
                int newr=delr[i]+r;
                int newc=delc[i]+c;
                if(newr>=0 && newc>=0 && newr<n && newc<m){
                    int newDiff=max(diff,abs(heights[newr][newc]-heights[r][c]));
                    if(newDiff < dist[newr][newc]){
                        dist[newr][newc]=newDiff;
                        pq.push({newDiff,{newr,newc}});
                    }
                }

            }



        }

        return dist[n-1][m-1];

        
    }
};
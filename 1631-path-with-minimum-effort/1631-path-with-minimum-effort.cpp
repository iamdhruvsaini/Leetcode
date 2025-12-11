class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        
        priority_queue<
            pair<int,pair<int,int>>,
            vector<pair<int,pair<int,int>>>,
            greater<pair<int,pair<int,int>>>
        >pq;

        int n=heights.size();
        int m=heights[0].size();

        pq.push({0,{0,0}});
        vector<vector<int>>mat(n,vector<int>(m,INT_MAX));
        mat[0][0]=0;


        int delr[]={0,1,0,-1};
        int delc[]={1,0,-1,0};

        while(!pq.empty()){
            auto node=pq.top();
            pq.pop();
            int diff=node.first;
            int r=node.second.first;
            int c=node.second.second;

            if(r==n-1 && c==m-1){
                return diff;
            }

            for(int i=0;i<4;i++){
                int nr=delr[i]+r;
                int nc=delc[i]+c;


                if(nr>=0 && nr<n && nc>=0 && nc<m){
                    int d=max(abs(heights[nr][nc]-heights[r][c]),diff);
                    if(d < mat[nr][nc]){
                        mat[nr][nc]=d;
                        pq.push({d,{nr,nc}});
                    }
                   
                }



            }
        }

        return -1;


    }
};
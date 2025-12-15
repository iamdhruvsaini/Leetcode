class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>vec(n,vector<int>(n,INT_MAX));

        for(int i=0;i<edges.size();i++){
            int node1=edges[i][0];
            int node2=edges[i][1];
            int wt=edges[i][2];
            vec[node1][node2]=wt;
            vec[node2][node1]=wt;
        }


        // update with the distance matrix using floyd warshall

        for(int via=0;via<n;via++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(vec[i][via]==INT_MAX || vec[via][j]==INT_MAX)continue;
                    vec[i][j]=min(vec[i][j],vec[i][via]+vec[via][j]);
                }
            }
        }

        int minCity=0;
        int minCount=INT_MAX;

        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=0;j<n;j++){
               if(i != j && vec[i][j]<=distanceThreshold){
                cnt++;
               }
            }
            if(cnt<=minCount){
                minCount=cnt;
                minCity=i;
            }
        }

        return minCity;




        
    }
};
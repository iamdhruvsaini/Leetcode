class Solution {
public:

    bool canPartitionGrid(vector<vector<int>>& grid) {
        vector<long long> rowSum, colSum;

        int n = grid.size(), m = grid[0].size();
        long long t=0;


        for (int i = 0; i < n; i++) {
            long long rsum = 0;
            for (int j = 0; j < m; j++) {
                rsum += grid[i][j];
                t+=grid[i][j];
            }
            rowSum.push_back(rsum);
        }

        for (int j = 0; j < m; j++) {
            long long csum = 0;
            for (int i = 0; i < n; i++) {
                csum += grid[i][j];
            }
            colSum.push_back(csum);
        }

        // h cut
        long long sum=0;
        for(int i=0;i<n;i++){
            sum+=rowSum[i];
            if(sum==t-sum)return 1;
        }      

        // v cut
        sum=0;
        for(int i=0;i<m;i++){
            sum+=colSum[i];
            if(sum==t-sum)return 1;
        }
        return 0;
    }
};
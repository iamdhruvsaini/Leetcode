class Solution {
public:
    int solve(vector<int>& obstacles,int index,int currentLane, vector<vector<int>> &dp){
        int n=obstacles.size()-1;
        if(n==index)return 0;

        if(dp[index][currentLane]!=-1)return dp[index][currentLane];

        if(obstacles[index+1]!=currentLane){
            return dp[index][currentLane]=solve(obstacles,index+1,currentLane,dp);
        }
        else{
            int ans=INT_MAX;
            for(int i=1;i<=3;i++){
                if(i!=currentLane && obstacles[index]!=i){
                   int temp=1+solve(obstacles,index,i,dp);
                   ans=min(ans,temp);
                }
            }
            return dp[index][currentLane]=ans;

        }
    }

    int solveTabulation(vector<int>& obstacles){
        int n=obstacles.size();
        vector<vector<int>>dp(n+1,vector<int>(4,0));
        dp[n-1][1]=0;
        dp[n-1][2]=0;
        dp[n-1][3]=0;

        for(int index=n-2;index>=0;index--){
           for(int j=1;j<=3;j++){
            if(obstacles[index+1]!=j){
                dp[index][j]=dp[index+1][j];
            }
            else{
                int ans=INT_MAX;
                for(int i=1;i<=3;i++){
                    if(i!=j && obstacles[index]!=i){
                        int temp=1+dp[index+1][i];
                        ans=min(ans,temp);
                    }
                }
                dp[index][j]=ans;
            }
           }
        }

        return min(dp[0][2],min(1 + dp[0][1], 1 + dp[0][3]));

    }


    int minSideJumps(vector<int>& obstacles) {

    //     int n=obstacles.size();
    //     vector<vector<int>>dp(n,vector<int>(4,-1));

    //    return solve(obstacles,0,2,dp);

        return solveTabulation(obstacles);
        
    }
};
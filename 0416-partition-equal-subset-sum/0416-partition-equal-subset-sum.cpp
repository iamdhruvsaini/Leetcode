class Solution {
public:
    int f(vector<int>& nums,int i,int t,vector<vector<int>>&dp){
        if(t==0)return 1;
        if(i==0)return nums[i]==t;
        if(dp[i][t]!=-1)return dp[i][t];

        int case1=f(nums,i-1,t,dp);
        int case2=0;
        if(t-nums[i]>=0){
            case2=f(nums,i-1,t-nums[i],dp);
        }
        return dp[i][t]=case1||case2;
    }
    bool canPartition(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum&1)return 0;
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(sum/2+1,0));

        // return f(nums,n-1,sum/2,dp);
        int t=sum/2;
        for(int i=0;i<n;i++)dp[i][0]=1;
        if(nums[0]<=t){
            dp[0][nums[0]]=1;
        }

        for(int i=1;i<n;i++){
            for(int j=1;j<=t;j++){
                int case1=dp[i-1][j];
                int case2=0;
                if(j-nums[i]>=0){
                    case2=dp[i-1][j-nums[i]];
                }
                dp[i][j]=case1||case2;

            }
        }
        return dp[n-1][t];

    }
};
class Solution {
public:
    bool solve(vector<int>& nums,int index,int sum, vector<vector<int>>&dp){
        if(sum == 0)return true;
        if(index==0)return sum==nums[index];
        if(dp[index][sum]!=-1)return dp[index][sum];

        // nottake
        int notTake=solve(nums,index-1,sum,dp);
        int take=false;
        if(sum - nums[index]>=0){
            take=solve(nums,index-1,sum-nums[index],dp);
        }
        return dp[index][sum]= take || notTake;
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int total=accumulate(nums.begin(),nums.end(),0);
        if(total & 1)return false;
        int target=total/2;
        vector<vector<int>>dp(n,vector<int>(target+1,0));


        for(int i=0;i<n;i++)dp[i][0]=1;
        if(nums[0]<=target)dp[0][nums[0]]=1;

        for(int index=1;index<n;index++){
            for(int sum=1;sum<=target;sum++){
                int notTake=dp[index-1][sum];
                int take=false;
                if(sum - nums[index]>=0){
                    take=dp[index-1][sum-nums[index]];
                }
                dp[index][sum]= take || notTake;

            }
        }
        return dp[n-1][target];

    }
};
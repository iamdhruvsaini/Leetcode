class Solution {
public:
    bool solve(vector<int>& nums,int index,int target,vector<vector<int>>&dp){
        if(target==0)return true;
        if(index==0)return nums[index]==target;
        if(dp[index][target]!=-1)return dp[index][target];
    
        bool exclude=solve(nums,index-1,target,dp);
        bool include=false;

        if(target<=nums[index]){
            include=solve(nums,index-1,target-nums[index],dp);
        }

        return dp[index][target]=include||exclude;
    
    }

    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum&1)return false;
        int target=sum/2;
        vector<vector<int>>dp(n,vector<int>(target+1,0));
        
        // return solve(nums,n-1,sum/2,dp);

        for(int i=0;i<n;i++){
            dp[i][0]=1;
        }
        if (nums[0] <= target) dp[0][nums[0]] = true;

        for(int i=1;i<n;i++){
            for(int j=1;j<=target;j++){
                bool exclude=dp[i-1][j];
                bool include=false;
                if(nums[i]<=j){
                    include=dp[i-1][j-nums[i]];
                }
    
               dp[i][j]=include||exclude;
            }
        }

        return dp[n-1][target];
    }
};
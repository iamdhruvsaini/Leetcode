class Solution {
public:
    int solve(vector<int>& nums,int index){

        if(index==0)return nums[0];
        if(index<0)return 0;
        // skip current
        int case1=solve(nums,index-1);
       
        int case2=nums[index]+solve(nums,index-2);

        return max(case1,case2);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,0);
        dp[1]=nums[0];

        for(int i=2;i<=n;i++){
            int case1=dp[i-1];
       
            int case2=nums[i-1]+dp[i-2];
            dp[i]=max(case1,case2);

        }

        return dp[n];


        // return solve(nums,n-1);
        
    }
};
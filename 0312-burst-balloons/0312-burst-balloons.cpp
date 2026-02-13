class Solution {
public:
    int solve(vector<int>& nums,int i,int j,vector<vector<int>>&dp){
        if(i>j)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int maxi=-1;
        for(int k=i;k<=j;k++){
            int total=nums[i-1]*nums[k]*nums[j+1] + solve(nums,i,k-1,dp)+solve(nums,k+1,j,dp);
            maxi=max(maxi,total);
        }
        return dp[i][j]=maxi;
    }
    int maxCoins(vector<int>& nums) {
        int c=nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        vector<vector<int>>dp(c+1,vector<int>(c+1,-1));
        return solve(nums,1,c,dp);
        
    }
};
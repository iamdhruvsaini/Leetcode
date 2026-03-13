class Solution {
public:

int f(vector<int>&arr,int i,int rob,vector<vector<int>>&dp){
    if(i==0){
        if(rob)return arr[i];
        return 0;
    }
    if(dp[i][rob+1]!=-1)return dp[i][rob+1];
    // not rob
    int case1=f(arr,i-1,1,dp);
    int case2=0;
    if(rob==-1 || rob==1){
        // can rob it
        case2=arr[i]+f(arr,i-1,0,dp);
    }
    return dp[i][rob+1] = max(case1, case2);
}
    int rob(vector<int>& nums) {
    int n=nums.size();
    vector<vector<int>>dp(n,vector<int>(n+1,-1));
     return f(nums,n-1,-1,dp);
        
    }
};


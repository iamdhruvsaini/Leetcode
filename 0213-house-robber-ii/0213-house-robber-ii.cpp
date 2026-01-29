class Solution {
public:
    int solve(vector<int>nums,int index,vector<int>&dp){
        if(index==0){
            return nums[0];
        }
        if(index<0)return 0;
        if(dp[index]!=-1)return dp[index];
        // skip current house
        int case1=solve(nums,index-1,dp);
        // rob the current house
        int case2=nums[index]+solve(nums,index-2,dp);

        return dp[index]=max(case1,case2);


    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return nums[0];
        vector<int>dp1(n,-1),dp2(n,-1);

        int first=solve(nums,n-2,dp1);
        vector<int>temp;
        for(int i=1;i<nums.size();i++){
            temp.push_back(nums[i]);
        }
        int second=solve(temp,temp.size()-1,dp2);
        return max(first,second);
        
    }
};
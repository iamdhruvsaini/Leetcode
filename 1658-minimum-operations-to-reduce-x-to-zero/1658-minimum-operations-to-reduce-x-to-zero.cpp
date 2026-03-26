class Solution {
public:
    int f(vector<int>& nums, int x,int i,int j, vector<vector<int>>&dp){
        if(x==0){
            return 0;
        }
        if(i>j){
            return 1e9;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        
        // case 1:
        int case1=1e9;
        if(x-nums[i]>=0){
            case1=1+f(nums,x-nums[i],i+1,j,dp);
        }
        int case2=1e9;
        if(x-nums[j]>=0){
            case2=1+f(nums,x-nums[j],i,j-1,dp);
        }

        return dp[i][j]=min(case1,case2);
    }
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        int i=0,j=0;
        int totalSum=accumulate(nums.begin(),nums.end(),0);
        int target=totalSum-x;

        // base case
        if(target==0)return n;
        if(target < 0) return -1;
        int sum=0;
        int ans=-1;

        while(j<n){
            sum+=nums[j];
            if(sum<target){
                j++;
            }
            else if(sum==target){
                ans=max(ans,j-i+1);
                j++;
              
            }
            else {
                // case when sum > target
                while(sum>target){
                    sum-=nums[i];
                    i++;
                }
                if(sum==target){
                    ans=max(ans,j-i+1);
                }
                j++;
            }
        }
       if(ans==-1)return -1;
       else return n-ans;
    }
};
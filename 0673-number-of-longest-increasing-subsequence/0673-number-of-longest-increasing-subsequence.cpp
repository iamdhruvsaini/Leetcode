class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp1(n,1);
        vector<int>dp2(n,1);

        int maxi=1,maxi_index=0;
        for(int i=0;i<n;i++){
            for(int j=i-1;j>=0;j--){
                if(nums[i]>nums[j] &&  dp1[j]+1 > dp1[i]){
                    dp1[i]=dp1[j]+1;
                    dp2[i]=dp2[j];

                }
                else if(nums[i]>nums[j] && dp1[j]+1 == dp1[i]){
                    dp2[i]+=dp2[j];
                }
            }
            if(dp1[i]>maxi){
                maxi=max(maxi,dp1[i]);
                maxi_index=i;
            }
        }
     
        int t=0;
        for(int i=0;i<n;i++){
            if(dp1[i]==maxi){
                t+=dp2[i];
            }
        }
        return t;
    }
};
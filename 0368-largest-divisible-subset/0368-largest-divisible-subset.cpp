class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int>dp(n,1);
        vector<int>hash(n,0);
        vector<int>ans;
        for(int i=0;i<n;i++)hash[i]=i;

        int maxi=-1,index=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0 && dp[j]+1 > dp[i]){
                    dp[i]=dp[j]+1;
                    hash[i]=j;
                }
            }
            if(dp[i]>maxi){
                maxi=dp[i];
                index=i;
            }
        }
        ans.push_back(nums[index]);
        while(index!=hash[index]){
            index=hash[index];
            ans.push_back(nums[index]);
        }

        reverse(ans.begin(),ans.end());
        return ans;
    }
};
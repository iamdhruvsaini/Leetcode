class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int>dp(n,1);
        vector<int>hash(n);
        for(int i=0;i<n;i++)hash[i]=i;

        int maxi=0,max_index=0;
        for(int i=0;i<n;i++){
            for(int j=i-1;j>=0;j--){
                if(nums[i]%nums[j]==0 && dp[j]+1 > dp[i]){
                    dp[i]=dp[j]+1;
                    hash[i]=j;
                }
            }
            if(maxi < dp[i]){
                maxi=dp[i];
                max_index=i;
            }
        }
        int index=max_index;
        vector<int>ans;
        ans.push_back(nums[index]);
        while(hash[index]!=index){
            index=hash[index];
            ans.push_back(nums[index]);
        }
        reverse(ans.begin(),ans.end());
        return ans;



        
    }
};
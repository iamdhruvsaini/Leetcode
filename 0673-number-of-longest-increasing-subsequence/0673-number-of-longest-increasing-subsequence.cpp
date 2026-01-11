class Solution {
public:
    int findNumberOfLIS(vector<int>& arr) {
        int n=arr.size();
        vector<int>dp(n,1),ct(n,1);

        int maxi=0,ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(arr[i]>arr[j] && dp[j]+1>dp[i]){
                    dp[i]=dp[j]+1;
                    ct[i]=ct[j];
                }
                else if(arr[i]>arr[j] && dp[j]+1==dp[i]){
                    ct[i] += ct[j];
                }
            }
            maxi=max(maxi,dp[i]);
        }

        for(int i=0;i<n;i++){
            if(dp[i]==maxi){
                ans+=ct[i];
            }
        }
        return ans;


        
    }
};
class Solution {
public:
    int solve(vector<int>& nums1, vector<int>& nums2, int index, bool swapped_at_prev,vector<vector<int>>&dp) {


    if (index == nums1.size()) { 
        return 0;
    }

    if(dp[index][swapped_at_prev]!=-1){
        return dp[index][swapped_at_prev];
    }

    int prev1 = nums1[index - 1];
    int prev2 = nums2[index - 1];
    if (swapped_at_prev) {
        swap(prev1, prev2);
    }

    int min_swaps = INT_MAX;

    if (nums1[index] > prev1 && nums2[index] > prev2) {
        int cost = solve(nums1, nums2, index + 1, false,dp);
        min_swaps = min(min_swaps, cost);
    }

    
    if (nums2[index] > prev1 && nums1[index] > prev2) { 
        int cost = 1 + solve(nums1, nums2, index + 1, true,dp);
        min_swaps = min(min_swaps, cost);
    }

    return dp[index][swapped_at_prev]=min_swaps; 

}

    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        vector<vector<int>>dp(n+1,vector<int>(3,-1));
        nums1.insert(nums1.begin(),-1);
        nums2.insert(nums2.begin(),-1);
        return solve(nums1,nums2,1,0,dp);
    }
};
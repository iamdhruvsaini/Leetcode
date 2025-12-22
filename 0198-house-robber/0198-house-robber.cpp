class Solution {
public:
    int solve(vector<int>& nums, int index, vector<int>& dp) {
        // 1. Base Case: If we go past the last house, we get 0 money.
        if (index >= nums.size()) {
            return 0;
        }

        // 2. Memoization: Return stored result if already calculated.
        if (dp[index] != -1) return dp[index];

        // 3. Option 1: Rob current house (and move to index + 2)
        int rob = nums[index] + solve(nums, index + 2, dp);

        // 4. Option 2: Skip current house (and move to index + 1)
        int skip = solve(nums, index + 1, dp);

        // 5. Store and return the max of both choices
        return dp[index] = max(rob, skip);
    }

    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return solve(nums, 0, dp);
    }
};
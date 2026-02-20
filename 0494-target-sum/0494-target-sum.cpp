class Solution {
public:

    int solve(vector<int>& nums, int target, int sum, int i,
              vector<vector<int>>& dp, int offset){

        if(i < 0)
            return sum == target;

        if(dp[i][sum + offset] != -1)
            return dp[i][sum + offset];

        int add = solve(nums, target, sum + nums[i], i-1, dp, offset);
        int sub = solve(nums, target, sum - nums[i], i-1, dp, offset);

        return dp[i][sum + offset] = add + sub;
    }

    int findTargetSumWays(vector<int>& nums, int target) {

        int total = accumulate(nums.begin(), nums.end(), 0);

        if(target > total || target < -total)
            return 0;

        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(2 * total + 1, -1));

        return solve(nums, target, 0, n-1, dp, total);
    }
};
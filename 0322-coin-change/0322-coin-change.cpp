class Solution {
public:
    int memo[10001]; // Array to store calculated results

    int solve(vector<int>& coins, int amount) {
        // Base cases
        if (amount == 0) return 0; // 0 coins needed to make 0 amount
        if (amount < 0) return -1;
        
        // If we already calculated this amount, return it
        if (memo[amount] != -2) return memo[amount];

        int minCoins = INT_MAX;

        for (int coin : coins) {
            int res = solve(coins, amount - coin);
            
            // If the sub-problem was solvable
            if (res != -1) {
                minCoins = min(minCoins, 1 + res);
            }
        }

        // Store result in memo: if minCoins is still INT_MAX, mark as -1
        return memo[amount] = (minCoins == INT_MAX) ? -1 : minCoins;
    }

    int coinChange(vector<int>& coins, int amount) {
        // Initialize memo with a dummy value (-2)
        fill(begin(memo), end(memo), -2);
        return solve(coins, amount);
    }
};
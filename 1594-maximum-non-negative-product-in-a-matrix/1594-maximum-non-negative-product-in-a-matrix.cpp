class Solution {
public:
    int mod = 1e9 + 7;
    int n, m;

    vector<vector<pair<long long,long long>>> dp;

    pair<long long,long long> f(vector<vector<int>>& grid, int i, int j) {
        if(i < 0 || j < 0) return {LLONG_MIN, LLONG_MAX};

        if(i == 0 && j == 0) {
            return {grid[0][0], grid[0][0]};
        }

        if(dp[i][j].first != LLONG_MIN) return dp[i][j];

        auto up = f(grid, i-1, j);
        auto left = f(grid, i, j-1);

        long long a = grid[i][j];

        vector<long long> candidates;

        if(up.first != LLONG_MIN) {
            candidates.push_back(up.first * a);
            candidates.push_back(up.second * a);
        }

        if(left.first != LLONG_MIN) {
            candidates.push_back(left.first * a);
            candidates.push_back(left.second * a);
        }

        long long maxi = *max_element(candidates.begin(), candidates.end());
        long long mini = *min_element(candidates.begin(), candidates.end());

        return dp[i][j] = {maxi, mini};
    }

    int maxProductPath(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        dp.assign(n, vector<pair<long long,long long>>(m, {LLONG_MIN, LLONG_MIN}));

        auto res = f(grid, n-1, m-1);

        if(res.first < 0) return -1;
        return res.first % mod;
    }
};
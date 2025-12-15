class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // 1. Define a large value for Infinity (but not INT_MAX to avoid overflow on addition)
        const int INF = 1e9; 
        
        // 2. Initialize matrix with INF
        vector<vector<int>> vec(n, vector<int>(n, INF));

        // 3. Distance from a node to itself is always 0
        for (int i = 0; i < n; i++) {
            vec[i][i] = 0;
        }

        // 4. Fill in the initial edge weights
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            vec[u][v] = wt;
            vec[v][u] = wt;
        }

        // 5. Floyd-Warshall Algorithm
        for (int via = 0; via < n; via++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    // Only update if path through 'via' is valid
                    if (vec[i][via] != INF && vec[via][j] != INF) {
                        vec[i][j] = min(vec[i][j], vec[i][via] + vec[via][j]);
                    }
                }
            }
        }

        int minCity = -1;
        int minCount = n + 1; // Initialize with a value larger than max possible neighbors

        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                // Count reachable cities (excluding self)
                if (i != j && vec[i][j] <= distanceThreshold) {
                    cnt++;
                }
            }

            // If count is smaller, update. 
            // If count is equal (<=), we take the current 'i' because it is larger 
            // (since the loop goes 0 to n-1, the later 'i' is the greater 'i').
            if (cnt <= minCount) {
                minCount = cnt;
                minCity = i;
            }
        }

        return minCity;
    }
};
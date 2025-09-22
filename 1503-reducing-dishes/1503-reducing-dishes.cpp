class Solution {
public:
    int solve(vector<int>& satisfaction,int index,int timeTaken){

        if(index==satisfaction.size()){
            return 0;
        }

        // include the current food item
        int inclusion=satisfaction[index]*timeTaken+solve(satisfaction,index+1,timeTaken+1);
        int exclusion=0+solve(satisfaction,index+1,timeTaken);

        return max(inclusion,exclusion);

    }

    int solveMemoization(vector<int>& satisfaction,int index,int timeTaken,vector<vector<int>>&dp){

        if(index==satisfaction.size()){
            return 0;
        }
        if(dp[index][timeTaken]!=-1){
            return dp[index][timeTaken];
        }

        // include the current food item
        int inclusion=satisfaction[index]*timeTaken+solveMemoization(satisfaction,index+1,timeTaken+1,dp);
        int exclusion=0+solveMemoization(satisfaction,index+1,timeTaken,dp);

        return dp[index][timeTaken]=max(inclusion,exclusion);

    }


    int maxSatisfaction(vector<int>& satisfaction) {

        int n=satisfaction.size();
        sort(satisfaction.begin(),satisfaction.end());
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return solveMemoization(satisfaction,0,1,dp);
    }
};
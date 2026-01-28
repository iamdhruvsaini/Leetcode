class Solution {
public:
    int climbStairs(int n) {
        vector<int>dp(n+1,0); 
        function<int(int)>fnc=[&](int a){
            if(a==0){
                return 1;
            }
            if(a<0)return 0;
            if(dp[a]!=0)return dp[a];
            // 1 step
            int case1=fnc(a-1);
            int case2=fnc(a-2);

            return dp[a]=case1+case2;
        };
        return fnc(n);
    }
};
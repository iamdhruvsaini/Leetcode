class Solution {

public:
    int mod=1e9+7;
    long long solve(long long base, long long exp){
        long long ans=1;
        while(exp){
            if(exp&1){
                // odd 
                ans=(ans*base)%mod;
            }
            base=(base*base)%mod;
            exp=exp/2;
        }
        return ans;
    }

    int countGoodNumbers(long long n) {
      long long evenValues=(n+1)/2;
      long long oddValues=n/2;

      long long oddPermutation=solve(4,oddValues);
      long long evenPermutation=solve(5,evenValues);
        
       return (oddPermutation*evenPermutation)%mod;
    }


};
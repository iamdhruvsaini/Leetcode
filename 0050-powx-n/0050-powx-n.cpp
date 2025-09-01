class Solution {
public:
    double myPow(double x, int n) {
        int v=n;
        double ans=1;
        while(n){
            if(n%2!=0){
                // ODD Number x*x^n-1
                ans=ans*x;
                // n--;
            }
            x=x*x;
            n=n/2;
        }

        if(v<0){
            ans = 1/ans;
        }
        return ans;

    }
};
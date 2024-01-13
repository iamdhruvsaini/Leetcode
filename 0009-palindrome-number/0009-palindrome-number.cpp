class Solution {
public:
    bool isPalindrome(int x) {
        int y=x;
        if(x%10==0 & x>0){
            return false;
        }
        if(x<0){
            return false;
        }
        long long rev=0;
        while(x>0){
            int rem=x%10;
            x=x/10;
            rev=rev*10+rem;

        }
        if(y==rev){
            return true;
        }
        return false;
        
    }
};
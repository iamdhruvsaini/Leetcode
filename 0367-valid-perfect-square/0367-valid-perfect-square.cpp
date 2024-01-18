class Solution {
public:
    bool isPerfectSquare(int num) {
    int s=0;
    long long e=num;
    long long mid=s+(e-s)/2;
    while(s<=e){
        long long int sq=mid*mid;
        if (sq==num){
            return true;
        }
        else if(sq>num){
            e=mid-1;
        }
        else{
            s=mid+1;
        }
        mid=s+(e-s)/2;
    }
        return false;
    }
};
class Solution {
public:
    int maxScore(vector<int>& arr, int k) {   

        int lsum=0,rsum=0,ans=INT_MIN;

        for(int i=0;i<k;i++){
            lsum+=arr[i];
            ans=max(ans,lsum);
        }

        int j=arr.size()-1;
        for(int i=k-1;i>=0;i--){
            rsum+=arr[j--];
            lsum-=arr[i];

            ans=max(ans,rsum+lsum);
        }

        return ans;

    }
};
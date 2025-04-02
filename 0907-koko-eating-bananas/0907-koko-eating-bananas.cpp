class Solution {
public:

    bool chk(vector<int>& piles, int t,int k){
        int i=0;
        while(i<piles.size() && t>=0){
            if(piles[i]<=k){
                t--;
            }
            else{
                int time=piles[i]/k;
                int left=piles[i]%k;
                t-=time;
                if(left!=0){
                    t--;
                }
            }
            i++;
        }
        if(t<0)return 0;
        return 1;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int s=1;
        int e=*max_element(piles.begin(),piles.end());
        int ans=-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(chk(piles,h,mid)){
                ans=mid;
                e=mid-1;
            }
            else{
                s=mid+1;
                
            }
        }
        return ans;
        
    }
};
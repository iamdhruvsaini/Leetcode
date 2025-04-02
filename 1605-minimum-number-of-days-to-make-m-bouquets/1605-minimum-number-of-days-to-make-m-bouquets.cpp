class Solution {
public:
    bool canMake(vector<int>& bloomDay, int m, int k,int n,int days){
        int w=0;
        for(int i=0;i<n;i++){
            if(bloomDay[i]<=days){
                w++;
                if(w==k){
                    //1 continus k seq spotted
                    m--;
                    //reset w=0
                    w=0;
                }
            }
            else{
                w=0;
            }
        }   
        if(m>0)return 0;
        return 1;    
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        //not possible as no. of flowers are less
        if(m > n/k)return -1;

        int s=0,e=*max_element(bloomDay.begin(),bloomDay.end());
        int ans=-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(canMake(bloomDay,m,k,n,mid)){
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
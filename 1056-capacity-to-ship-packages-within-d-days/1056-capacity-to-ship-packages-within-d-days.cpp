class Solution {
public:
    bool checkPossible(vector<int>& weights, int days,int weight){
        int total=0;
        int i=0;
        while(i<weights.size()){
            int temp=total+weights[i];
            if(weights[i]>weight)return 0;
            if(temp>weight){
                days--;
                total=0;
            }
            total+=weights[i];
            i++;
        }
        if(total!=0)days--;

        return days>=0;
        
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int s=*max_element(weights.begin(),weights.end()),e=accumulate(weights.begin(),weights.end(),0);
        // sort(weights.begin(),weights.end());
        int ans=-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(checkPossible(weights,days,mid)){
                ans=mid;
                //least weight we have to find
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return ans;
    }
};
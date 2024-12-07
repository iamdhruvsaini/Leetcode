class Solution {
public:
    bool chk(vector<int>& nums,int mid,int op){
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>mid){
                count+=ceil((double)(nums[i]-mid)/mid);
            }   
        }
        cout<<count<<" ";
        return count<=op;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int maxi=*max_element(nums.begin(),nums.end());

        int s=1;
        int e=maxi;
        int ans=-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(chk(nums,mid,maxOperations)){
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
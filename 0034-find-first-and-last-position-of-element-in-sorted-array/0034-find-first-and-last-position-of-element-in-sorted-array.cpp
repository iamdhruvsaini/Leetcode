class Solution {
public:
    vector<int> searchRange(vector<int>& arr, int target) {
        int s=0,e=arr.size()-1;
        int ans=-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(arr[mid]==target){
                ans=mid;
                e=mid-1;
            }
            else if(arr[mid]>target){
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        if(ans==-1)return {ans,ans};
        int last=-1;
        for(int i=ans;i<arr.size();i++){
            if(arr[i]==target){
                last=i;
            }
            else{
                break;
            }
        }

        return {ans,last};
    }
};
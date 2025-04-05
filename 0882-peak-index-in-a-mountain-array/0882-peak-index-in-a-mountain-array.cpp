class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        if(arr[0]>arr[1])return arr[0];
        if(arr[arr.size()-1]>arr[arr.size()-2])return arr[arr.size()-1];
        int s=1,e=arr.size()-2;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1]){
                return mid;
            }
            else if(arr[mid]>arr[mid-1]){
                //inc ramp
                s=mid+1;
            }
            else{
                e=mid-1;
            }
        }
        
        return -1;
    }
};
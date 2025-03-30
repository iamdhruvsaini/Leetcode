class Solution {
public:
    int findMin(vector<int>& arr) {
        int s=0,e=arr.size()-1;
        int mini=INT_MAX;
        while(s<=e){
            int mid=s+(e-s)/2;
            //identify the sorted half
            if(arr[mid]>=arr[s]){
                //left part is sorted so minimum will be arr[s]
                mini=min(mini,arr[s]);
                //check in unsorted part
                s=mid+1;
            }
            else{
                //right part is sorted minimum is arr[mid] 
                mini=min(mini,arr[mid]);
                //check in unsorted part
                e=mid-1;
            }
        }
        return mini;
    }
};
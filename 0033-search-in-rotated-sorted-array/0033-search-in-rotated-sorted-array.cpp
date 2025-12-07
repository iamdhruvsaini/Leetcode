class Solution {
public:
    int search(vector<int>&arr, int target) {
        int s=0,e=arr.size()-1;

        while(s<=e){
            int mid=s+(e-s)/2;
            if(arr[mid]==target){
                return mid;
            }
            else if(arr[mid]>=arr[s]){
                // left part is sorted
                if(target<=arr[mid] && target >=arr[s]){
                    e=mid-1;
                }
                else{
                    s=mid+1;
                }
            }
            else {
                // right part is sorted
                if(target>=arr[mid] && target <=arr[e]){
                    s=mid+1;
                }
                else{
                    e=mid-1;
                }
            }
        }

        return -1;
    }
};
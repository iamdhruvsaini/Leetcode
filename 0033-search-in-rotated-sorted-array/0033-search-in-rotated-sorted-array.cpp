class Solution {
public:
    int search(vector<int>& arr, int target) {
        int s=0,e=arr.size()-1;
        while(s<=e){
            int mid=s+(e-s)/2;

            if(arr[mid]==target)return mid;

            else if(arr[mid]>=arr[s]){
                //left part is sorted
                if(target>=arr[s] && target<=arr[mid]){
                    e=mid-1;
                }
                else{
                    s=mid+1;
                }
            }else{
                //right part is sorted
                 if(target<=arr[e] && target>=arr[mid]){
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
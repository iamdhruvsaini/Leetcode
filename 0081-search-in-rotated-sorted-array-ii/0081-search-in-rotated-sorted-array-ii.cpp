class Solution {
public:
    bool search(vector<int>& arr, int target) {

        int s=0;
        int e=arr.size()-1;

        while(s<=e){
            int mid=s+(e-s)/2;

            if(arr[mid]==target){
                return true;
            }

            if(arr[mid]==arr[s] && arr[mid]==arr[e]){
                s++;
                e--;
                continue;
            }
            //identify sorted part
            else if(arr[mid]>=arr[s]){
                //left part is sorted
                if(target <= arr[mid] && target>=arr[s]){
                    e=mid-1;
                }
                else{
                    s=mid+1;
                }
            }
            else{
                //right part is sorted
                 if(target >= arr[mid] && target <=arr[e] ){
                    s=mid+1;
                }
                else{
                    e=mid-1;
                }
            }
        }
        return 0;
        
    }
};
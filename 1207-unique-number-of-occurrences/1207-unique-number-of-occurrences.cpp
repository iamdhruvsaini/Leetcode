class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        int k=0;
        int cnt=1;
        for(int i=0;i<n-1;i++){
            if(arr[i]==arr[i+1]){
                cnt++;
            }
            else{
                arr[k++]=cnt;
                cnt=1;
            }
        }
        //cnt++;
        arr[k++]=cnt;
        sort(arr.begin(),arr.begin()+k);
        for(int i=0;i<k-1;i++){
            if(arr[i]==arr[i+1]){
                return false;
            }
        }
        return true;
        
    }
};
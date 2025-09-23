class Solution {
public:
    int findLis(vector<vector<int>>& arr){
        vector<int>temp;
        temp.push_back(arr[0][1]);
        for(int i=1;i<arr.size();i++){
            if(arr[i][1]>temp[temp.size()-1]){
                temp.push_back(arr[i][1]);
            }else{
                int index=lower_bound(temp.begin(),temp.end(),arr[i][1])-temp.begin();
                temp[index]=arr[i][1];
            }
        }

        return temp.size();
    }

    static bool comparator(vector<int> arr1,vector<int> arr2){
        if(arr1[0]==arr2[0]){
            return arr1[1]>arr2[1];
        }
        else{
            return arr1[0]<arr2[0];
        }


    }
    int maxEnvelopes(vector<vector<int>>& arr) {

        sort(arr.begin(),arr.end(),comparator);
        return findLis(arr);
        
    }
};
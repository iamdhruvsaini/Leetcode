class Solution {
public:
    int findMax(vector<vector<int>>& mat,int col){
        int maxi=INT_MIN;
        int r=-1;
        for(int i=0;i<mat.size();i++){
            if(mat[i][col]>maxi){
                maxi=mat[i][col];
                r=i;
            }
        }
        return r;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int rows=mat.size();
        int cols=mat[0].size();

        int s=0;
        int e=cols-1;

        while(s<=e){
            int mid=s+(e-s)/2;
            int r=findMax(mat,mid);


            int left=mid-1>=0 ? mat[r][mid-1] :-1;
            int right=mid+1<cols ? mat[r][mid+1]:-1;

            int element = mat[r][mid];
            if(element > left && element > right){
                return {r,mid};
            }
            else if(element > left){
                s=mid+1;
            }
            else{
                e=mid-1;
            } 
        }
        return {-1,-1};
    }
};
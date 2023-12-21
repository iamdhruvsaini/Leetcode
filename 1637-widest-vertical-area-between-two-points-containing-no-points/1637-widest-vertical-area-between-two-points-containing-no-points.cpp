class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        vector<int>temp;
        for(int i=0;i<points.size();i++){
            int x=points[i][0];
            temp.emplace(temp.end(),x);
        }
        // for(auto i:temp){
        //     cout<<i<<" ";
        // }
        int maxi=INT_MIN;
        sort(temp.begin(),temp.end());
        for(int i=0;i<temp.size()-1;i++){
            int diff=temp[i+1]-temp[i];
            maxi=max(diff,maxi);
        }

        return maxi;
    }
};
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int i=0;
        int n=intervals.size();
        vector<vector<int>>ans;
        while(i<n && intervals[i][1] < newInterval[0]){
            ans.push_back(intervals[i]);
            i++;
        }
        int newintervals=newInterval[0];
        int newintervale=newInterval[1];
        while(i<n && intervals[i][0]<=newInterval[1]){
            newintervals=min(intervals[i][0],newintervals);
            newintervale=max(intervals[i][1],newintervale);
            i++;
        }
        ans.push_back({newintervals,newintervale});
        while(i<n){
             ans.push_back(intervals[i]);
            i++;
        }
        return ans;
    }
};
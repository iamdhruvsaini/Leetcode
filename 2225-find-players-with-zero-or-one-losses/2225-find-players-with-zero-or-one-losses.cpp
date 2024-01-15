class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        set<int>winner;
        set<int>loser;
        map<int,int>mp;
        for(int i=0;i<matches.size();i++){
            winner.insert(matches[i][0]);
            loser.insert(matches[i][1]);
            mp[matches[i][1]]++;
        }
        
        vector<int>v1;
        for(auto it=winner.begin();it!=winner.end();it++){
            if(loser.find(*it)==loser.end()){
                v1.push_back(*it);
            }
        }
        vector<int>v2;
        for(auto i=loser.begin();i!=loser.end();i++){
            if(mp[*i]==1)v2.push_back(*i);
        }
        
        return {v1,v2};
        
        
        
    }
};
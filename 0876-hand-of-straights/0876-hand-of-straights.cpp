class Solution {
public:
    bool isNStraightHand(vector<int>& arr, int g) {
        int n=arr.size();
        if(n%g!=0)return false;
        map<int,int>mp;

        for(auto i:arr){
            mp[i]++;
        }

        while(!mp.empty()){
            int top=mp.begin()->first;

            for(int i=0;i<g;i++){
                if(mp.find(top+i)!=mp.end()){
                    mp[top+i]--;
                    if(mp[top+i]<=0){
                        mp.erase(top+i);
                    }
                }
                else{
                    return false;
                }
            }
        }

        return true;
    }
       
};
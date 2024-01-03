class Solution {
public:
    int numberOfBeams(vector<string>& bank){
        vector<int>temp;
        for(int i=0;i<bank.size();i++){
            int cnt = count(bank[i].begin(),bank[i].end(),'1');
            if(cnt!=0) temp.push_back(cnt);
        }
        int ans=0;
        if(temp.size()>1){
            for (int i = 0; i < temp.size() - 1; i++) {
            ans = ans + temp[i] * temp[i + 1];
            }   
        }
        return ans;
    }
};
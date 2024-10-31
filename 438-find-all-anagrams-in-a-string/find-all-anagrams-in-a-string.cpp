class Solution {
public:
    bool check(vector<int>&freq,vector<int>&temp){
        for(int i=0;i<26;i++){
            if(freq[i]!=temp[i])return 0;
        }
        return 1;
    }
    vector<int> findAnagrams(string s, string p) {
        if(p.size() > s.size())return {};
        
        // return {1};
        vector<int>freq(26,0);
        vector<int>temp(26,0);
        vector<int>ans;
        for(int i=0;i<p.size();i++){
            int index=p[i]-'a';
            temp[index]++;
            index=s[i]-'a';
            freq[index]++;
        }
        if(check(freq,temp)){
            ans.push_back(0);
        }
        int left=0;
        int right=p.size()-1;
        while(right<s.size()-1){

            right++;
            int index=s[left]-'a';
            freq[index]--;
            index=s[right]-'a';
            freq[index]++;
            left++;
            if(check(freq,temp)){
                ans.push_back(left);
            }
        }
        return ans;

    }   
};
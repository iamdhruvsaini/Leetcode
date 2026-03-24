class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size();
       
        vector<int>freq(3,-1);
        int ans=0;
        for(int i=0;i<n;i++){
            freq[s[i]-'a']=i;
            if(freq[0]!=-1 && freq[1]!=-1 && freq[2]!=-1){
                ans+=*min_element(freq.begin(),freq.end())+1;
            }
        }
        return ans;
       
        
    }
};
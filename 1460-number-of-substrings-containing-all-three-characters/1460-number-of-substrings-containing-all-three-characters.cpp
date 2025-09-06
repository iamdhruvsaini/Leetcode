class Solution {
public:
    int numberOfSubstrings(string s) {
        int hashing[3]={-1,-1,-1};
        int cnt=0;
       for(int i=0;i<s.size();i++){
            hashing[s[i]-'a']=i;
            cnt=cnt+min(hashing[0],min(hashing[1],hashing[2]))+1;
       }

       return cnt;
    }
};
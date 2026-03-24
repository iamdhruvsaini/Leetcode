class Solution {
public:
    int numberOfSubstrings(string s) {

        int n=s.size();
        int hash[3]={-1,-1,-1};
        int i=0,j=0;
        int total=0;

        while(j<n){
            hash[s[j]-'a']++;
            while(hash[0]!=-1 && hash[1]!=-1 && hash[2]!=-1){
                total+=n-j;
                hash[s[i]-'a']--;
                i++;
            }
            j++;

        }

        return total;
        
    }
};
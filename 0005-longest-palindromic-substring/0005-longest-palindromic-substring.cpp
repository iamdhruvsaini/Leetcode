class Solution {
public:
    string longestPalindrome(string arr) {
        int n=arr.size();
        if(n<=1)return arr;
        string ans="";

        int maxlen=INT_MIN;
        for(int i=0;i<n;i++){
            // check for odd substrings
            int s=i-1;
            int e=i+1;
           
            while(s>=0 && e<n && arr[e]==arr[s]){
                s--;
                e++;
            }

            int oddlen=e-s-1;
            maxlen=max(maxlen,oddlen);
            if(maxlen==oddlen){
                ans=arr.substr(s+1,oddlen);
            }

            // even len
            s=i;
            e=i+1;
            while(s>=0 && e<n && arr[e]==arr[s]){
                s--;
                e++;
            }

            int evenlen=e-s-1;
            maxlen=max(maxlen,evenlen);
            if(maxlen==evenlen){
                ans=arr.substr(s+1,evenlen);
            }

        }

        return ans;
    }
};
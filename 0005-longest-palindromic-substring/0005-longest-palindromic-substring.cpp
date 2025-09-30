class Solution {
public:

string solve(string &s){
  int n=s.size();
  
  int maxi=-1;
  int start=-1;
  
  for(int i=0;i<n;i++){
    
    // even palindrome
    int left=i;
    int right=i+1;
    int evenLen=-1;
    
    while(left>=0 && right<n && s[left]==s[right]){
      evenLen=max(evenLen,right-left+1);
      left--;
      right++;
      
    }
    
    if(evenLen>maxi){
      maxi=evenLen;
      start=left+1;
    }
    
    // odd len palindrome
    left=i-1;
    right=i+1;
    int oddLen=-1;
    
    while( left>=0 && right<n && s[left]==s[right]){
      oddLen=max(oddLen,right-left+1);
      left--;
      right++;
    }
    
    if(oddLen>maxi){
      maxi=oddLen;
      start=left+1;
    }
  }
  
  
  
  if(maxi==-1)return s.substr(0,1);
  else{
    return s.substr(start,maxi);
  }  
  
}

    string longestPalindrome(string s) {
        return solve(s);
        
    }
};
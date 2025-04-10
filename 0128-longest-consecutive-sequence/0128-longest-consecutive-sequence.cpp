class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>s;

        for(auto i : nums){
            s.insert(i);
        }

        int maxCnt=0;

        for(int i:s){
            if(s.find(i-1)==s.end()){
                // this is start element
                int cnt=1;
                int val=i+1;
                while(s.find(val)!=s.end()){
                    cnt++;
                    val++;
                }
                maxCnt=max(maxCnt,cnt);
            }
        }
        return maxCnt;

    }
};
class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int>word_freq1(26,0);
        vector<bool>word_freq2(26,0);
        vector<int>word2_freq1(26,0);
        vector<bool>word2_freq2(26,0);
        if(word1.size()!=word2.size())return false;
        for(auto ch:word1){
            word_freq1[ch-'a']++;
            word_freq2[ch-'a']=true;
        }
        for(auto ch:word2){
            word2_freq1[ch-'a']++;
            word2_freq2[ch-'a']=true;
        }
        sort(word_freq1.begin(),word_freq1.end());
        sort(word2_freq1.begin(),word2_freq1.end());
        return word_freq1==word2_freq1 && word2_freq2==word_freq2;

        
    }
};
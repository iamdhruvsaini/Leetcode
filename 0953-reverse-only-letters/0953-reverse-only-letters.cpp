class Solution {
public:
    string reverseOnlyLetters(string str) {
          int s = 0, e = str.length() - 1;

        while (s < e) {
            // Skip non-letter characters from the start
            while (s < e && !isalpha(str[s])) {
                s++;
            }

            // Skip non-letter characters from the end
            while (s < e && !isalpha(str[e])) {
                e--;
            }

            // Swap only if both str[s] and str[e] are letters
            if (s < e) {
                swap(str[s], str[e]);
                s++;
                e--;
            }
        }
        return str;
    }
};
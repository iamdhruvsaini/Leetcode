class Solution {
public:
    vector<int> p;

    void run_manacher(const string &s) {
        int n = s.length();
        p.assign(n, 1);

        int l = 0, r = 0;

        for (int i = 0; i < n; i++) {
            if (i < r) {
                int mirror = l + r - i;
                p[i] = min(r - i, p[mirror]);
            }

            while (i + p[i] < n &&
                   i - p[i] >= 0 &&
                   s[i + p[i]] == s[i - p[i]]) {
                p[i]++;
            }

            if (i + p[i] > r) {
                l = i - p[i];
                r = i + p[i];
            }
        }
    }

    string longestPalindrome(string s) {
        if (s.empty()) return "";

        // Build transformed string
        string t;
        for (char c : s) {
            t += '#';
            t += c;
        }
        t += '#';

        run_manacher(t);

        int maxLen = 0, center = 0;
        for (int i = 0; i < (int)t.size(); i++) {
            if (p[i] > maxLen) {
                maxLen = p[i];
                center = i;
            }
        }

        int start = (center - maxLen + 1) / 2;
        return s.substr(start, maxLen - 1);
    }
};

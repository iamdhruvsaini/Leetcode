#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>

class Solution {
public:
    int beautySum(string s) {
        int totalBeauty = 0;
        int n = s.size();

        // Outer loop: start of the substring
        for (int i = 0; i < n; i++) {
            // Frequency map for the current substring
            std::vector<int> freq(26, 0);

            // Inner loop: end of the substring (expanding the window)
            for (int j = i; j < n; j++) {
                // Increment frequency of the new character
                freq[s[j] - 'a']++;

                // Find min and max frequencies for the current window
                int minFreq = INT_MAX;
                int maxFreq = 0;

                for (int count : freq) {
                    if (count > 0) {
                        minFreq = std::min(minFreq, count);
                    }
                    maxFreq = std::max(maxFreq, count);
                }

                // Add the beauty of the current substring to the total sum
                totalBeauty += (maxFreq - minFreq);
            }
        }
        return totalBeauty;
    }
};
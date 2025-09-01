class Solution {
public:
    void solve(vector<string> &ans, string& temp, int open, int close, int n) {
        // Base case: If the string is the correct length, we've found a valid combination.
        if (temp.size() == 2 * n) {
            ans.push_back(temp);
            return;
        }

        // Rule 1: Add an opening parenthesis if we haven't used all 'n' of them.
        if (open < n) {
            temp.push_back('(');
            solve(ans, temp, open + 1, close, n);
            temp.pop_back(); // Backtrack: remove the last character to explore other paths
        }

        // Rule 2: Add a closing parenthesis only if it's a valid move (i.e., we have an open parenthesis to close).
        if (close < open) {
            temp.push_back(')');
            solve(ans, temp, open, close + 1, n);
            temp.pop_back(); // Backtrack: remove the last character
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string temp = "";
        solve(ans, temp, 0, 0, n);
        return ans;
    }
};
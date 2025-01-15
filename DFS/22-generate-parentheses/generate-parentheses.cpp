class Solution {
public:
    void backtrack(int open, int close, int n, string s, vector<string>& res) {
        // Base case: If the current string has 2 * n characters, it's valid
        if (s.length() == 2 * n) {
            res.push_back(s); // Add the valid combination to the result
            return;
        }

        // Add an open parenthesis if the number of open parentheses is less than n
        if (open < n) {
            backtrack(open + 1, close, n, s + "(", res);
        }

        // Add a close parenthesis if the number of close parentheses is less than open
        if (close < open) {
            backtrack(open, close + 1, n, s + ")", res);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res; // Result vector to store all valid combinations
        string s = "";      // Current string being formed
        backtrack(0, 0, n, s, res); // Start backtracking with 0 open and 0 close parentheses
        return res;
    }
};

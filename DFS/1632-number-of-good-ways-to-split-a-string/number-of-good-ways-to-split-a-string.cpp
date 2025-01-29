
class Solution {
public:
    int numSplits(string s) {
        int n = s.length();
        vector<int> prefix(n, 0), suffix(n, 0);
        unordered_set<char> seen;

        // Count unique characters in the prefix
        for (int i = 0; i < n; i++) {
            seen.insert(s[i]);
            prefix[i] = seen.size();
        }

        seen.clear();  // Reset set for suffix

        // Count unique characters in the suffix
        for (int i = n - 1; i >= 0; i--) {
            seen.insert(s[i]);
            suffix[i] = seen.size();
        }

        int count = 0;
        for (int i = 0; i < n - 1; i++) {
            if (prefix[i] == suffix[i + 1]) {
                count++;
            }
        }

        return count;
    }
};
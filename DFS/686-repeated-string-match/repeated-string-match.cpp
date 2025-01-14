class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int aLen = a.size();
        int bLen = b.size();
        int repetitions = bLen / aLen; // Minimum repetitions needed to cover 'b'

        string repeatedA = a;
        for (int i = 1; i <= repetitions +2; ++i) {
            if (repeatedA.find(b) != string::npos) {
                return i;
            }
            repeatedA += a; // Add one more 'a' if not found
        }
        return -1; // If 'b' is not a substring even after sufficient repetitions
    }
};

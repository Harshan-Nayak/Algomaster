class Solution {
public:
bool isSubsequence(string s, string t) {
    auto it = t.begin();
    for (char c : s) {
        it = find(it, t.end(), c);
        if (it == t.end()) return false;
        ++it;
    }
    return true;
}
    int numMatchingSubseq(string s, vector<string>& words) {
        int count = 0;
        for (string& word : words) {
            if (isSubsequence(word, s)) {
                count++;
            }
        }
        return count;
  }
};
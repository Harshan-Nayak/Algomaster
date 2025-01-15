class Solution {
public:

    void backtrack(vector<vector<int>>& res, vector<int>& path, int target, vector<int>& candidates, int start) {
        // Base case: If the target is 0, add the current path to the result
        if (target == 0) {
            res.push_back(path);
            return;
        }

        // Iterate over candidates starting from the current index
        for (int i = start; i < candidates.size(); i++) {
            // Skip if the candidate is greater than the remaining target
            if (target >= candidates[i]) {
                // Choose the current candidate
                target -= candidates[i];
                path.push_back(candidates[i]);

                // Recurse, allowing reuse of the current candidate by keeping `i` as the starting index
                backtrack(res, path, target, candidates, i);

                // Backtrack: Undo the choice
                path.pop_back();
                target += candidates[i];
            }
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res; // To store all valid combinations
        vector<int> path;        // To build a single combination

        // Start backtracking from index 0
        backtrack(res, path, target, candidates, 0);

        return res;
    }
};

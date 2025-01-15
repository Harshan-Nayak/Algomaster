class Solution {
public:
    void backtrack(vector<int>& candidates, vector<vector<int>>& res, vector<int>& path, int target, int start) {
        // Base case: If the target is 0, we found a valid combination
        if (target == 0) {
            res.push_back(path);
            return;
        }

        // Iterate over candidates starting from the current index
        for (int i = start; i < candidates.size(); i++) {
            // Skip duplicates
            if (i > start && candidates[i] == candidates[i - 1]) continue;

            // If the candidate is greater than the remaining target, break
            if (candidates[i] > target) break;

            // Choose the current candidate
            path.push_back(candidates[i]);

            target -= candidates[i];

            // Recurse with reduced target and the next starting index (i + 1)
            backtrack(candidates, res, path, target , i + 1);

            // Backtrack: Undo the choice
            target += candidates[i];
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res; // To store all unique combinations
        vector<int> path;        // To store the current combination

        // Sort the candidates to handle duplicates and enable pruning
        sort(candidates.begin(), candidates.end());

        // Start backtracking
        backtrack(candidates, res, path, target, 0);

        return res;
    }
};

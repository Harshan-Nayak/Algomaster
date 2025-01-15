class Solution {
public:
    void backtrack(vector<vector<int>>& res, vector<int>& path, vector<int>& nums, vector<bool>& used) {
        // Base case: If the path is a complete permutation
        if (path.size() == nums.size()) {
            res.push_back(path);
            return;
        }

        // Iterate over all elements in nums
        for (int i = 0; i < nums.size(); i++) {
            // Skip if this element is already used in the current permutation
            if (used[i]) continue;

            // Include this element in the path
            path.push_back(nums[i]);
            used[i] = true;

            // Recurse to build the next level of the permutation
            backtrack(res, path, nums, used);

            // Backtrack: Remove the element and mark it as unused
            path.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res; // To store all permutations
        vector<int> path;        // To build a single permutation
        vector<bool> used(nums.size(), false); // To track whether an element is used

        // Start backtracking
        backtrack(res, path, nums, used);

        return res;
    }
};

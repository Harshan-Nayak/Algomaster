class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int f = INT_MAX; // First smallest number
        int s = INT_MAX; // Second smallest number
        int t = INT_MAX; // Third smallest number

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] <= f) {
                // Update the first smallest number
                f = nums[i];
            } else if (nums[i] <= s) {
                // Update the second smallest number
                s = nums[i];
            } else if (nums[i] > s) {
                // Found a number greater than both f and s
                t = nums[i];
                return true; // Triplet found
            }
        }
        return false; // No triplet found
    }
};
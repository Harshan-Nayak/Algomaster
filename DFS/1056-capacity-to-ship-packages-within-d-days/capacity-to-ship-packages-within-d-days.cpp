class Solution {
public:
    bool isFeasible(vector<int>& weights, int days, int mid) {
        int ctDays = 1, sum = 0; // Start with 1 day
        for (int wt : weights) {
            sum += wt;
            if (sum > mid) { // If the sum exceeds mid, we need a new day
                ctDays++;
                sum = wt; // Reset sum to the current weight
            }
        }
        return ctDays <= days; // Check if feasible within given days
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end()); // Minimum capacity
        int high = accumulate(weights.begin(), weights.end(), 0); // Maximum capacity
        int result = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isFeasible(weights, days, mid)) {
                result = mid; // Update result if feasible
                high = mid - 1; // Try for a smaller capacity
            } else {
                low = mid + 1; // Increase capacity
            }
        }
        return result;
    }
};

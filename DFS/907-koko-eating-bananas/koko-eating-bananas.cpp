class Solution {
public:

    bool ifFeasible(vector<int>& piles, int h, int mid) {
        long long ct = 0; // Use long long to avoid overflow
        for (auto it : piles) {
            // Calculate hours for current pile (using integer division that mimics ceiling)
            ct += (long long)(it + mid - 1) / mid; // Cast to long long to prevent overflow
        }
        return ct <= h; // Return true if we can eat all piles within h hours
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());

        int res = high;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (ifFeasible(piles, h, mid)) {
                res = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return res;
    }
};

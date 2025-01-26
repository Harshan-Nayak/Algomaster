class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int low = INT_MAX;   // Track the lowest price so far
        int high = INT_MIN;  // Track the highest price after the lowest price
        int profit = 0;      // Initialize profit to 0

        for (int i = 0; i < prices.size(); i++) {
            // Update the lowest price if the current price is lower
            if (prices[i] < low) {
                low = prices[i];
                high = INT_MIN; // Reset high since we found a new low
            }
            // Update the highest price if the current price is higher
            else if (prices[i] > high) {
                high = prices[i];
                // Calculate the profit if we sell on the current day
                if (high - low > profit) {
                    profit = high - low;
                }
            }
        }

        return profit; // Return the maximum profit
    }
};
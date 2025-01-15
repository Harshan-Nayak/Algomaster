#include <vector>
#include <queue> // For priority_queue (min-heap)
using namespace std;

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        // Min-heap to store the smallest jumps where ladders are used
        priority_queue<int, vector<int>, greater<int>> minHeap;

        // Loop through each building
        for (int i = 0; i < heights.size() - 1; i++) {
            // Calculate the height difference between the current and next building
            int jump = heights[i + 1] - heights[i];

            // If the next building is taller, we need to climb
            if (jump > 0) {
                // Use a ladder for this jump and store the jump in the min-heap
                minHeap.push(jump);

                // If we've used more ladders than we have, replace the smallest ladder usage with bricks
                if (minHeap.size() > ladders) {
                    // Get the smallest jump from the heap
                    int smallestJump = minHeap.top();
                    minHeap.pop();

                    // Use bricks for this smallest jump
                    bricks -= smallestJump;

                    // If we run out of bricks, we can't go further
                    if (bricks < 0) {
                        return i; // Return the current building index
                    }
                }
            }
        }

        // If we can reach the last building, return the last index
        return heights.size() - 1;
    }
};
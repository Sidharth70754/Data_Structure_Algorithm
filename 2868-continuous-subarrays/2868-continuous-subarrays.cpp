class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int n = nums.size();
        long long totalSubarray = 0;

        int start = 0; // Starting index of the sliding window

        // Deques to store indices of max and min elements in the current window
        deque<int> maxDeque, minDeque;

        for (int end = 0; end < n; end++) {
            // Maintain the maxDeque for the current window
            while (!maxDeque.empty() && nums[maxDeque.back()] <= nums[end]) {
                maxDeque.pop_back();
            }
            maxDeque.push_back(end);

            // Maintain the minDeque for the current window
            while (!minDeque.empty() && nums[minDeque.back()] >= nums[end]) {
                minDeque.pop_back();
            }
            minDeque.push_back(end);

            // Shrink the window if the condition is violated
            while (nums[maxDeque.front()] - nums[minDeque.front()] > 2) {
                start++;
                // Remove elements outside the current window
                if (maxDeque.front() < start) {
                    maxDeque.pop_front();
                }
                if (minDeque.front() < start) {
                    minDeque.pop_front();
                }
            }

            // Count valid subarrays ending at 'end'
            totalSubarray += (end - start + 1);
        }

        return totalSubarray;
    }
};

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int ind = -1;
        int n = nums.size();
        
        // Step 1: Find the first decreasing element from the back
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                ind = i;
                break;
            }
        }

        // Step 2: If no decreasing element is found, reverse the entire array
        if (ind == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        // Step 3: Find the next larger element from the end
        for (int i = n - 1; i > ind; i--) {
            if (nums[i] > nums[ind]) {
                swap(nums[i], nums[ind]);
                break;
            }
        }

        // Step 4: Reverse the portion of the array from ind + 1 to the end
        reverse(nums.begin() + ind + 1, nums.end());
    }
};

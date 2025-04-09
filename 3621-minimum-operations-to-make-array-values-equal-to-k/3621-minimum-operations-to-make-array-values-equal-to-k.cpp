class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_set<int> count;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < k) {
                return -1;
            }
            if (nums[i] > k) {
                count.insert(nums[i]);
            }
        }
        return count.size();
    }
};

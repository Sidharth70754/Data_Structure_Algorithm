class Solution {
public:
    void subset(int idx, vector<int> &nums, vector<int> &current, vector<vector<int>> &result) {
        // Add current subset to result
        result.push_back(current);

        // Generate further subsets
        for (int i = idx; i < nums.size(); i++) {
            current.push_back(nums[i]);              // choose
            subset(i + 1, nums, current, result);    // explore
            current.pop_back();                      // un-choose
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        subset(0, nums, current, result);
        return result;
    }
};
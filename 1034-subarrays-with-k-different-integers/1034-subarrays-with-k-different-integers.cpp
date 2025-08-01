class Solution {
public:
    int atMostK(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        int left = 0, count = 0;

        for (int right = 0; right < nums.size(); right++) {
            if (mpp[nums[right]] == 0) {
                k--;
            }
            mpp[nums[right]]++;

            while (k < 0) {
                mpp[nums[left]]--;
                if (mpp[nums[left]] == 0) {
                    mpp.erase(nums[left]);
                    k++;
                }
                left++;
            }

            count += (right - left + 1);
        }

        return count;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMostK(nums, k) - atMostK(nums, k - 1);
    }
};

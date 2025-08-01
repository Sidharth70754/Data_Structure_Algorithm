class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        double sum =0;
        for (int i = 0; i < k; i++) {
             sum += nums[i];
        }
        double maxi = sum;
        for (int i = k; i < n; i++) {
            sum = sum - nums[i - k] + nums[i];
            maxi = max(maxi, sum);
        }
        return maxi / k;
    }
};
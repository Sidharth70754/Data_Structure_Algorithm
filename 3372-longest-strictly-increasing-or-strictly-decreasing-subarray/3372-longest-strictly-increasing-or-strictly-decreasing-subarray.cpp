class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int longest = 1;
        int strictely_increasing = 1;
        int strictely_decreasing = 1;
        for(int i = 1; i< n; i++){
            if(nums[i] > nums[i-1]) strictely_increasing++;
            else                    strictely_increasing = 1;

            if(nums[i] < nums[i-1]) strictely_decreasing++;
            else                    strictely_decreasing = 1;

            longest = max({longest, strictely_increasing, strictely_decreasing});

        }
        return longest;
    }
};
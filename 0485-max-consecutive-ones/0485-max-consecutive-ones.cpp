class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int l =0, maxlen = 0;
        for(int r = 0; r < nums.size(); r++){
            if(nums[r] == 0){
                l = r + 1;
            }
            maxlen = max(maxlen, r-l+1);
        }
        return maxlen;
    }
};
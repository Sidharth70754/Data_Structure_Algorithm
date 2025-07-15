class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0;
        int fatest = 0;
        int currentEnd = 0;
        for(int i = 0; i < nums.size() -1; i++){
            fatest = max(fatest, i + nums[i]);

            if(i == currentEnd){
                ++jumps;
            currentEnd = fatest;
            }
        }
        return jumps;
    }
};
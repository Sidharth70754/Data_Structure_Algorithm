class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count=0,max=0,i=0;
        while(i<nums.size()){
            if(nums[i]==1){
                count++;
                if(count>max) max=count;
            }else count=0;
            i++;
        }
        return max;
    }
};
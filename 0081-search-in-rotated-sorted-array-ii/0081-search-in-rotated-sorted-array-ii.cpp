class Solution {
public:
    bool search(vector<int>& nums, int target) {
        // int n = nums.size();
        // int low = 0;
        // int high = n -1;

        // while(low <= high){
        //     int mid = (low + high) /2;
        
        // if(arr[mid] == target) return true;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(nums[i] == target){
                return true;
            }
        }
        return false;
    }
};
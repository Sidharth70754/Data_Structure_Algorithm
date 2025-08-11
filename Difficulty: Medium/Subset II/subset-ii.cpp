// User function Template for C++

class Solution {

  public:
  
    void subset(int idx, vector<int> &nums, vector<int> &ds, vector<vector<int>> &ans){
        ans.push_back(ds);
        for(int i = idx; i < nums.size(); i++){
            if(i != idx && nums[i] == nums[i -1]) continue;
            ds.push_back(nums[i]);
            subset(i + 1, nums, ds, ans);
            ds.pop_back();
        }
    }
  
    vector<vector<int>> printUniqueSubsets(vector<int>& nums) {
        vector<int> ds;
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        subset(0, nums, ds , ans);
        return ans;
        
    }
};
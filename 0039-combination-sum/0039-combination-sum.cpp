class Solution {
public:
    void backtrack (int idx, vector<int>& candidates, int target , vector<int> &current, vector<vector<int>> &result){
        if(target == 0){
            result.push_back(current);
            return ;
        }
        if(idx >= candidates.size() || target < 0){
            return ;
        }

        current.push_back(candidates[idx]);
        backtrack(idx, candidates, target - candidates[idx], current , result );
        current.pop_back();

        backtrack(idx + 1, candidates, target, current, result);

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> current;
        vector<vector<int>> result;
        backtrack(0, candidates, target, current , result );
        return result;
    }
};
class Solution {
public:
    void backtrack(int idx, vector<int>& candidates, int target, vector<int>& current, vector<vector<int>>& result) {
        if (target == 0) {
            result.push_back(current);
            return;
        }

        for (int i = idx; i < candidates.size(); i++) {
            if (i > idx && candidates[i] == candidates[i - 1]) continue;  
            if (candidates[i] > target) break; 

            current.push_back(candidates[i]);
            backtrack(i + 1, candidates, target - candidates[i], current, result);  
            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end()); 
        vector<int> current;
        vector<vector<int>> result;
        backtrack(0, candidates, target, current, result);
        return result;    
    }
};

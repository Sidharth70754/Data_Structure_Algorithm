class Solution {
    #define LL Long Long
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        if(n<2) return 0;

        long long top_sum = accumulate(grid[0].begin(), grid[0].end(),0LL);
        long long bottom_sum = 0;

        long long min_sum = LONG_MAX;
        for(int i =0 ;i < n ; i++){
            top_sum -= grid[0][i];
            min_sum = min(min_sum, max(top_sum, bottom_sum));
            bottom_sum += grid[1][i];
        }
        return min_sum;
    }
};
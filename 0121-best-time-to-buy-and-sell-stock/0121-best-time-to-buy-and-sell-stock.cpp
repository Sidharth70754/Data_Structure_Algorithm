class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = prices[0];
        int n = prices.size();
        int maxprofit = 0;
        for(int i = 0; i < n ; i++){
            int cost = prices[i] - mini;
            mini = min(mini, prices[i]);
            maxprofit  = max(maxprofit, cost);
        }
        return maxprofit;
    }
};